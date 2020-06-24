<html>
<head>
  <title>Temperature & Humidity Database</title>
  <style type="text/css">
    table {
      text-align: center;
      border-collapse: collapse;
      border: 1px solid #d4d4d4;
    }

    tr:nth-child(even) {
      background: #d4d4d4;
    }

    th,
    td {
      padding: 10px 30px;
    }

    th {
      border-bottom: 1px solid #d4d4d4;
    }
  </style>
</head>

<body>
  <h1 align="center">온도 습도</h1>
  <?php
        $conn = mysqli_connect('relaxleep.ckbl1fdsxpkw.ap-northeast-2.rds.amazonaws.com','user','00000000','relaxleep');
        $result = mysqli_query($conn, "SELECT * FROM TemHum_Table");

        echo("<table>");
        echo("<tr><td>번호</td><td>시간</td><td>온도</td><td>습도</td></tr>");
        while($row = mysqli_fetch_assoc($result)) 
        {
          for($i=0; $i<sizeof($result); $i++)
          {
            $count++;
            echo("<tr><td>".$count."</td><td>".$row['Time']."</td><td>".$row['Temperature']."</td><td>".$row['Humidity']."</td></tr>");
            //이상징후알림
            if($row['Temperature']>27)
            {
              echo "<script type=\"text/javascript\">alert('온도가 높습니다');</script>";
            }
            if($row['Temperature']<20)
            {
              echo "<script type=\"text/javascript\">alert('온도가 낮습니다');</script>";
            }
            if($row['Humidity']>70)
            {
              echo "<script type=\"text/javascript\">alert('습도가 높습니다');</script>";
            }
            if($row['Humidity']<40)
            {
              echo "<script type=\"text/javascript\">alert('습도가 낮습니다');</script>";
            }
          }

        }
        echo("</table>");
        ?>
</body>

</html>