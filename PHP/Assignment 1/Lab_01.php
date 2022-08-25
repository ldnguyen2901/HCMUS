<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Document</title>
</head>

<body>
	
	<?php error_reporting (E_ALL ^ E_NOTICE); ?>

	<!-- Đọc file này và hiển thị lên trang web thành dạng table (có đường kẻ bảng) -->
	<?php
	$path = "C:\\xampp\\htdocs\\Hcmus\\StudentData.txt";
	$myfile = fopen($path, "rb") or die("Can't open file!");
	echo <<<EOF

	<style>
	body{
		background-color: #262626;
		color: rgb(242, 242, 242);
	}
	table, td, th {
		table-layout: fixed;
		width: 300px;
		border-collapse: collapse;
		border: 3px solid black;
		text-align: center;
	}
	</style>
	EOF;
	echo '<table>';

	echo '<tr><th>StudentID</th><th>StudentName</th><th>Birthday</th>
		<th>AverageMark</th>';

	echo '<tr>';
	while (!feof($myfile)) {
			$info = fgets($myfile);
			$parts = explode('|', $info);
			echo "<tr>
					<td>$parts[0]</td>
					<td>$parts[1]</td>
					<td>$parts[2]</td>
					<td>$parts[3]</td>
				</tr>";
	}
	echo "</tr></table>";
	fclose($myfile);
	?>
	
	<?php 
		$ID = $_GET['ID'];
		$StudentName = $_GET['Name'];
	?>
	
</body>
</html>


