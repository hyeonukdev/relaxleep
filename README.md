# relaxleep
---
## 실행영상링크
[유튜브연동(움직임)](https://youtu.be/7npybVEjDr8)<br>
[유튜브연동(차트)](https://youtu.be/8lWx__wI_3s)

## 개발기간
- 2019.03.02.~ 12.22. (약9개월)

### 샤용 기술
- .Net Framewor

### 상세 내용
- 4개의 로드셀을 이용하여 무게중심의 분포도를 알아내고 이를 통해 간략한 환자의 자세를 파악함
- 환자 자세 파악으로 낙상의 위험이 있는지를 파악하고 오랜 시간 일정 자세를 유지했을 경우(오랜 시간 무게중심의 분포에 변화가 없을 경우) 알림을 주어 욕창이 발생 할 수 있다는 경고를 줌
- 환자의 실시간 상태를 PC프로그램으로 모니터링함으로써 환자를 보다 효과적으로 케어

#### 이전 버전
fallbed ver1.0.0 : 환자를 위한 낙상알림 및 욕창판단 프로그램<br>

#### 개선사항
fallbed ver1.1.0 : 낙상 및 욕창 판단을 위한 분석용 프로그램<br>
-> ver1.0.0로부터 불필요한 기능 삭제, 필요한 기능 추가

- 삭제
  - 아날로드미터
  - 회원가입/로그인
  - 환자별침대관리
- 추가
  - 영상출력모드 : 라즈베리파이 카메라를 이용한 실시간 스트리밍을 하는 웹 페이지 출력
  - 로드셀차트모드 : 네 개의 무게값에 대한 차트를 그림
  - 체중차트모드 : 체중에 대한 차트를 그림
  - 무게중심차트모드 : 무게중심에 대한 차트를 그림

- fallbed ver1.1.1 변경사항
  - 초당 들어오는 데이터 개수 조정
  - 조건에 따른 DB저장
  - 일정 이상 움직임이 감지되면 그 때의 환자 자세를 촬영하는 기능 추가 예정
---
