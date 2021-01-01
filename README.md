# relaxleep
---
## 실행영상링크
[유튜브연동(움직임)](https://youtu.be/7npybVEjDr8)<br>
[유튜브연동(차트)](https://youtu.be/8lWx__wI_3s)

## 개발기간
- 2019.03.02.~ 12.22. (약9개월)

### 적용기술
Sensor : 라즈베리파이, 적외선카메라, 블루투스 스피커, 아두이노, 온습도센서, 소리감지센서, CO2농도센서, 조도센서<br>
영상처리서버 : Amazon EC2 (Ubuntu 16.04)<br>
DB서버 : AWS RDS (MySQL)<br>
수면판단기능 구현 : Python<br>
수면 모니터링 웹 구현 : HTML/CSS/JS, PHP<br>
수면 관리 안드로이드 앱 구현 : Java<br>
라이브러리 : OpenCV 3.3<br>

### 상세 내용
- 웹 Front-End
- DB관리

- Data를 이용해 Table 그리기
  - local 값으로 Table
  - cvs 파일을 불러와 Table 
  - RDS 값을 불러와 Table
- Data를 이용해 Chart 그리기
  - local 값으로 Chart
  - cvs 파일을 불러와 Chart 
  - RDS 값을 불러와 Chart
- 목소리 재생 및 자장가
  - static으로 자장가 업로드
  - 실시간으로 업로드 후 재생
- Relaxleep site 디자인 구성
- Arduino 값을 raspberry에 직렬 연결하여 값 불러오기
- HW통합 후 DB upload
- 수면시간 원형차트 그리기 
---
