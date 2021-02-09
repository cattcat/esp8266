<?php
    $dbhost = 'localhost';
    $dbuser = 'root';
    $dbpass = '';
    $dbname = 'temphumid';
    $conn = mysql_connect($dbhost, $dbuser, $dbpass) ;//連接資料庫
    mysql_query("SET NAMES 'utf8'");//設定語系
    mysql_select_db($dbname);

    $sql = "DELETE FROM `data`";//查詢整個表單
    $result = mysql_query($sql) ;

	echo "資料清除完成";
	


	mysql_close($conn);
?>
<br><input type="button" value="回主頁" onclick="window.location.href='index.php'" ><br>