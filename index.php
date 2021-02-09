
<input type="button" value="刪除所有資料" onclick="window.location.href='delete.php'" ><br>

<?php
    $dbhost = 'localhost';
    $dbuser = 'root';
    $dbpass = '';
    $dbname = 'temphumid';
    $conn = mysql_connect($dbhost, $dbuser, $dbpass) ;//連接資料庫
    mysql_query("SET NAMES 'utf8'");//設定語系
    mysql_select_db($dbname);

    $sql = "select * from data";//查詢整個表單
    $result = mysql_query($sql) ;
	$num_rows = mysql_num_rows($result);
    while($row = mysql_fetch_array($result)){//印出資料
		echo"溫度:";
        echo $row['temperature']."濕度:";
		echo $row['humidity']."	時間:";
		echo $row['datetime']."<br>";
		
    }
	

	echo "目前總共有 $num_rows 筆資料";
?>