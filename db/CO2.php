<html>
  <head>
    <title>CO2 Database</title>
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
    <h1 align="center">이산화탄소</h1>
        <?php
        $conn = mysqli_connect('relaxleep.ckbl1fdsxpkw.ap-northeast-2.rds.amazonaws.com','user','00000000','relaxleep');
        $result = mysqli_query($conn, "SELECT * FROM CO2_Table");
        
        echo("<table>");
        echo("<tr><td>번호</td><td>시간</td><td>co2</td></tr>");
        while($row = mysqli_fetch_assoc($result)) 
        {
          for($i=0; $i<sizeof($result); $i++)
          {
          $count++;
          echo("<tr><td>".$count."</td><td>".$row['Time']."</td><td>".$row['Value']."</td></tr>");
          }
          
        }
        echo("</table>");
        ?>

        <!--    echo("아래는 테스트");
           //테이블그리기코드
           //테스트해볼것
             echo("<table>");
             for($i=0; $i<sizeof($result); $i++)
             {
             $count++;
             echo("<tr><td>".$count."</td><td>".$row['Time']."</td><td>".$row['CO2']."</td></tr>");
             }
             echo("</table>");
        -->
  </body>
</html>