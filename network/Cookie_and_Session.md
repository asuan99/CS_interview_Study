# Cookie와 Session의 차이점에 대해서 설명해주세요.

- **자료 조사**
    
    <aside>
    🔥 **쿠키와 세션을 사용하는 이유?**
    
    HTTP 특징이자 약점을 보완하기 위해서 사용됩니다.
    
    </aside>
    
    - **HTTP (HyperText Transfer Protocol)**
        
        HTTP란 `Client`(Internet Explorer, Chrome, Firefox)와 `Server`(웹 서버 eg: httpd, nginx, etc…)간의 웹 상에서의 통신을 위한 `Protocol`(규약)입니다.
        
        **HTTP의 특징**
        
        1. Connectionless 프로토콜 (비연결 지향)
            
            클라이언트가 서버에 요청(Request)을 했을 때, 그 요청에 맞는 응답(Response)을 보낸 후 연결을 끊는 처리방식이다.
            
            즉, 한 가지 요청에 대한 응답을 받으면 그 연결을 끊어버리는 것을 의미합니다. 연결에 대한 리소스를 줄일 수 있는 장점이 있지만, 같은 클라이언트에게 오는 요청 또한 계속 연결/해제 해야 한다는 단점이 존재합니다.
            
        2. Stateless 프로토콜
            
            Connectionless의 특징을 가지기 때문에 서버와의 통신이 끝나면 상태 정보를 유지하지 않고 버리는 특성이 있다.
            
            그렇기에, 클라이언트와 첫 번째 통신에서 데이터를 주고받았다 해도, 두 번째 통신에서 이전 데이터를 유지하지 않는다.
            
            하지만, 실제로는 데이터 유지가 필요한 경우가 많습니다.
            
        
        <aside>
        🔥 정보가 유지되지 않으면, 매번 페이지를 이동할 때마다 로그인을 다시 하거나, 상품을 선택했는데 구매 페이지에서 선택한 상품의 정보가 없거나 하는 등의 일이 발생할 수 있다.
        
        → 따라서, Stateful 경우를 대처하기 위해 쿠키와 세션을 사용한다.
        **쿠키와 세션의 차이점은 크게 상태 정보의 저장 위치**이다. **쿠키는 ‘클라이언트(= 로컬 PC)’에 저장하고, 세션은 ‘서버’에 저장한다.**
        
        </aside>
        
    - **Cookie**
        
        <img src="https://github.com/BangDori/CS_interview_Study/blob/main/network/img/Cookie-%EA%B0%95%EB%B3%91%EC%A4%80.png" alt="Cookie" width="288px" /> <br/>
        HTTP의 일종으로 사용자가 어떠한 웹 사이트를 방문할 경우, 그 사이트가 사용하고 있는 서버에서 사용자의 컴퓨터에 저장하는 작은 기록 정보 파일입니다. HTTP에서 클라이언트의 상태 정보를 클라이언트의 PC에 저장하였다가, 필요시 정보를 참조하거나 재사용할 수 있다.
        
        - **Cookie 특징**
            1. 이름, 값, 만료일(저장 기간 설정), 경로 정보로 구성되어 있다.
            2. 클라이언트에 총 300개의 쿠키를 저장할 수 있다. 보안 상의 이유뿐만 아니라 브라우저의 성능과 관련된 이유로 웹 브라우저에서 지원되는 쿠키의 개수는 다릅니다. 
            3. 하나의 도메인 당 20개의 쿠키를 가질 수 있다.
            4. 하나의 쿠키는 4KB까지 저장 가능하다.
        - **Cookie의 동작 순서와 예제 코드**
            1. 클라이언트에서 서버로 HTTP 요청을 보냅니다. ex) 로그인
                
                ```jsx
                /**
                 * auth login 함수
                 * @param {*} form 이메일, 비밀번호
                 * @returns status, accessToken, refreshToken, expire
                 */
                export async function login(data) {
                  try {
                    const result = await axios
                      .post(`${MAIN_SERVER}/api/auth/login`, data)
                      .then((res) => res.data);
                
                    return result;
                  } catch (e) {
                    console.log(e);
                  }
                }
                ```
                
            2. 서버에서 응답으로 HTTP 쿠키를 설정합니다. 이때, 쿠키의 이름, 값, 만료 날짜, 경로 등의 정보를 설정할 수 있습니다. ex) JWT token
                
                ```tsx
                @HttpCode(200)
                @Post("/login")
                @OpenAPI({
                  description: "로그인을 진행합니다",
                })
                @UseBefore()
                public async login(@Body() loginUserDto: LoginUserDto, @Res() res: Response) {
                	// 로그인 요청 처리
                  const result = await this.authService.localLogin(loginUserDto);
                
                	// 요청에 실패한 경우
                  if (result.status === false) {
                    return res.status(200).send(result);
                  }
                
                	// 요청에 성공한 경우
                  const user = result.user!;
                
                	// 토큰 생성
                  const { accessToken, refreshToken } = generateToken(user);
                
                	// 서버 측에 user의 ID와 refreshToken에 대한 정보를 저장
                  await this.authService.saveRefreshToken(user.id, refreshToken);
                
                	// 클라이어트로 아래 정보를 전달
                  return {
                    status: result.status,
                    expire: 15 * this.minute,
                    accessToken,
                    refreshToken,
                  };
                }
                ```
                
            3. 클라이언트의 브라우저는 서버에서 전송된 쿠키를 저장합니다.
                
                ```jsx
                const onLogin = useCallback(
                    async (e) => {
                      e.preventDefault();
                
                      try {
                        const { status, accessToken, refreshToken, expire } = await login(form);
                
                				// 정상적으로 통신이 이루어졌다면...
                        if (status) {
                          // 최초 로그인 시 accessToken, refreshToken 저장
                          setTokens(accessToken, refreshToken, expire);
                
                          // HTTP 재 요청
                          window.location.reload();
                        } else {
                          resetForm();
                          throw new Error('유저 정보가 일치하지 않습니다.');
                        }
                      } catch (e) {
                        setError(e.message);
                      }
                    },
                    [form, resetForm],
                  );
                ```
                
            4. 이후 클라이언트에서 다시 서버로 요청을 보낼 때, 브라우저는 저장된 쿠키를 함께 전송합니다.
                
                ```jsx
                /**
                 * Article Write 함수
                 * @param {*} data 게시글 정보 (제목, 내용, 사진 등)
                 */
                export async function write(data) {
                  try {
                    const result = await axios
                      .post(`${MAIN_SERVER}/api/auth/logout`, data, {
                        headers: {
                          Authorization: 'Bearer ' + accessToken,
                        },
                      })
                      .then((res) => res.data);
                
                    return result;
                  } catch (e) {
                    console.log(e);
                  }
                }
                ```
                
                <aside>
                🔥 **헤더에 쿠키를 담아서 전송하는 이유가 무엇인가요?**
                
                쿠키는 클라이언트와 서버 간의 상태를 유지하고 세션 관리를 위해 사용됩니다. 쿠키를 헤더에 포함시켜 서버에 전송함으로써 서버는 해당 클라이언트의 상태 정보를 확인할 수 있습니다.
                
                </aside>
                
                쿠키는, 클라이언트에서 저장되기 때문에, 클라이언트가 다시 서버로 요청을 보낼 때 매번 쿠키를 전송하지 않아도 됩니다. 다음과 같이 설정해주면, 클라이언트에서 저장된 쿠키는 서버에 요청을 보낼 때마다 자동으로 헤더에 포함되어 전송됩니다.
                
                ```jsx
                const instance = axios.create({
                  withCredentials: true
                });
                
                /**
                 * Article Write 함수
                 * @param {*} data 게시글 정보 (제목, 내용, 사진 등)
                 */
                export async function write(data) {
                  try {
                    const result = await instance
                      .post(`${MAIN_SERVER}/api/auth/logout`, data)
                      .then((res) => res.data);
                
                    return result;
                  } catch (e) {
                    console.log(e);
                  }
                }
                ```
                
            5. 서버에서 요청으로 전송된 쿠키를 읽어서 해당 정보를 처리합니다.
    - **Session**
        
        일정 시간동안 같은 사용자(브라우저)로부터 들어오는 일련의 요구를 하나의 상태로 보고, 그 상태를 일정하게 유지시키는 기술이다. 여기서 일정 시간은 방문자가 웹 브라우저를 통해 웹 서버에 접속한 시점으로부터 웹 브라우저를 종료하여 연결을 끝내는 시점을 말한다.
        
        즉, **세션**은 서버에서 클라이언트의 상태를 유지하기 위한 임시 저장 공간입니다.
        
        - **Session 특징**
            1. 웹 서버에 웹 컨테이너의 상태를 유지하기 위한 정보를 저장한다.
            2. 웹 서버의 저장되는 쿠키(= 세션 쿠키)
            3. 브라우저를 닫거나, 서버에서 세션을 삭제했을때만 삭제가 되고, 서버에서 관리하기 떄문에 쿠키보다 비교적 보안이 좋다.
            4. 서버 용량이 허용하는 한 저장 데이터에 제한이 없다.
            5. 각 클라이언트 고유 Session ID를 부여한다. ID로 클라이언트를 구분하여 각 클라이언트 요구에 맞는 서비스 제공이 가능하다.
        - **Session의 동작 순서**
            1. 클라이언트가 페이지를 요청한다. (사용자가 웹 사이트에 접근)
                
                ```jsx
                axios.get('/api/data', {
                  headers: { 'sessionID': '세션 ID 값' }
                })
                ```
                
            2. 서버는 접근한 클라이언트의 Request-Header 필드인 Cookie를 확인하여, 클라이언트가 해당 sessionID를 보냈는지 확인한다.
                
                ```jsx
                // header에 sessionID가 포함되어 있는지 확인
                const sessionID = req.headers['sessionID'];
                ```
                
            3. sessionID가 존재하지 않는다면, 서버는 sessionID를 생성해 클라이언트에게 돌려준다.
                
                ```jsx
                // sessionID가 없다면...
                const generate_sessionID = generateSessionID();
                
                // 클라이어트로 아래 정보를 전달
                return {
                  status: result.status,
                	sessionID: generate_sessionID,
                };
                ```
                
            4. 서버에서 클라이언트로 돌려준 sessionID를 쿠키에 사용해 서버에 저장한다.
                
                ```jsx
                // 쿠키에 세션 ID 저장하는 예시 (Express.js)
                res.cookie('sessionId', sessionId, {
                  maxAge: 60 * 60 * 1000, // 쿠키 만료 시간 설정 (1시간)
                  httpOnly: true, // 클라이언트에서 쿠키에 접근할 수 없도록 설정
                  secure: true, // HTTPS 프로토콜에서만 쿠키에 접근할 수 있도록 설정
                  sameSite: 'none' // Cross-site Request Forgery (CSRF) 방지를 위한 설정
                });
                ```
                
            5. 클라이언트는 재접속 시, 이 쿠키를 이용하여 sessionID값을 서버에 전달
    - **차이점**
        - 쿠키와 세션은 비슷한 역할을 하며, 동작 원리도 비슷하다. 그 이유는 세션도 결국 쿠키를 사용하기 때문이다.
        - 큰 차이점은 사용자의 정보가 저장되는 위치이다. 쿠키는 서버의 자원을 전혀 사용하지 않지만, 세션은 서버의 자원을 사용한다.
        - 쿠키는 클라이언트 로컬에 정보를 저장하기 때문에, 변질되거나 request에서 스니핑 당할 우려가 있어 보안에 취약하지만, 세션은 쿠키를 이용해 sessionID만 저장하고 나머지 클라이언트 정보는 서버에서 보관하기 때문에 비교적 보안성이 높다.
        - 라이프 사이클은 쿠키는 브라우저를 종료해도 정보가 유지될 수 있다. 반면 세션은 브라우저가 종료되면 만료기간에 상관없이 삭제된다.
- **답안**
    
    쿠키와 세션은 비슷한 역할을 하며, 동작 원리 또한 비슷하지만, 서로 다른 개념입니다.
    
    우선 쿠키는 서버의 자원을 전혀 사용하지 않고 클라이언트의 로컬 브라우저에 저장되는 작은 데이터 파일로 브라우저를 종료해도 클라이언트의 정보가 유지된다는 장점이 있지만, 클라이언트의 로컬에 정보를 저장하기 때문에 보안에 취약하다는 단점이 있습니다.
    
    반면 세션은 클라이언트 로컬에는 sessionID만 저장하고 클라이언트의 정보는 서버에 보관하기 때문에 비교적 보안성이 높다는 장점이 있습니다. 하지만, 서버에 클라이언트의 정보를 저장하기 때문에 서버의 자원을 사용한다는 단점이 있습니다.
    
- **[꼬리 질문1]**
    
    ### Cookie를 서버의 데이터베이스에 저장하는 이유를 설명하세요.
    
    - **답안**
        
        쿠키는 클라이언트와 서버 간의 상태 정보를 저장하고 전송하는 방법 중 하나입니다. 이러한 쿠키를 데이터베이스에 저장하는 이유는 클라이언트 측에 저장되는 쿠키를, 데이터베이스에 저장하여 서버 측에서 관리하기 때문에 보안성이 높아지고 또한, 데이터베이스에 쿠키 정보를 저장하여 클라이언트의 정보를 계속 유지해 사용자 경험을 높여줄 수 있기 때문입니다.
        
- **[꼬리 질문2]**
    
    ### 금융권에서 로그인 상태를 유지하기 위해서 Cookie와 Session중에 무엇을 사용하는 것이 좋을지 설명해주세요.
    
    - **답안**
        
        금융권에서는 아무래도 성능보다는 보안이 우선시 되어야 한다고 생각하기 때문에, 로컬 브라우저에 자신의 정보를 저장하는 Cookie보다는, 서버에 정보를 저장하는 Session이 더 유리할 것 같습니다.
        
- **참고 자료**
    1. 네트워크 - (박영덕 교수님)
    2. HTTP(Hypertext Transfer Protocol)란? - 티베트 모래여우 ([url](https://tibetsandfox.tistory.com/18))
    3. [메디스트림 개발팀] HTTP (HyperText Transfer Protocol) - Medistream ([url](https://careers.medistream.co.kr/2bdf11f1-7969-442e-8877-ff7e97380db4#cf027dfe-24b2-489d-b7d0-d90708a0bb40))
    4. 리액트를 다루는 기술 - 김민준
    5. 쿠키(Cookie), 세션(Session) 특징 및 차이 - 개발메모/WEB ([url](https://hahahoho5915.tistory.com/32))
    6. stackoverflow ([url](https://stackoverflow.com/questions/3268159/is-it-better-to-store-user-data-in-a-database-rather-than-in-cookies))
