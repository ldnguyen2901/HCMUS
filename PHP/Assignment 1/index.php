<?php
$path = "C:\\xampp\\htdocs\\Hcmus\\StudentData.txt";
$myfile = fopen($path, "r") or die("Unable to open File");
// y thu 1 cua thay
$max = 5.0;
$min = 5.0;
while (!feof($myfile)) {
	$keyword = fgets($myfile);
	$tach = explode("|", $keyword);
	if ($max <= $tach[3]) {
		$max = $tach[3];
	} else if ($min > $tach[3]) {
		$min = $tach[3];
	}
}
fseek($myfile, 0);
while (!feof($myfile)) {
	$keyword = fgets($myfile);
	$tach = explode("|", $keyword);

	echo "<table>
	<tr>";

	if ($max == $tach[3]) {
		echo "<td id='stt_max'>$tach[0]</td>
			  <td id='name_max'>$tach[1]</td>
			  <td id='birth_max'>$tach[2]</td>
			  <td id='avgmark_max'>$tach[3]</td>";
	} else if ($min == $tach[3]) {
		echo "<td id='stt_min'>$tach[0]</td>
			  <td id='name_min'>$tach[1]</td>
			  <td id='birth_min'>$tach[2]</td>
			  <td id='avgmark_min'>$tach[3]</td>";
	} else {
		echo "<td id='stt'>$tach[0]</td>
			  <td id='name'>$tach[1]</td>
			  <td id='birth'>$tach[2]</td>
			  <td id='avgmark'>$tach[3]</td>";
	}
	echo "</tr>
	</table>";
}

// y thu 2.1 cua thay
fseek($myfile, 0);
if (!empty($_GET['id'])) {
	$user_id = $_GET['id'];

	$check_id = 0;
	while (!feof($myfile)) {
		$keyword_id = fgets($myfile);
		$tach_id = explode("|", $keyword_id);

		if ($user_id == $tach_id[0]) {
			echo "<h3> Search Found</h3>";
			$check_id = 1;

			echo "<table>
			<tr>";
			foreach ($tach_id as $data_id) {
				echo "<td>$data_id</td>";
			}
			echo "</tr>
			</table>";
		}
	}
	if ($check_id == 0) {
		echo "<h3>Not Found</h3>";
	}
}
// //y thu 2.2 cua thay
fseek($myfile, 0);
if (!empty($_GET['name'])) {
	$user_name = $_GET['name'];

	$check_name = 0;
	while (!feof($myfile)) {
		$keyword_name = fgets($myfile);
		$tach_name = explode("|", $keyword_name);

		if (stripos($tach_name[1], $user_name) > 0) {
			echo "<h3> Search Found</h3>";
			$check_name = 1;

			echo "<table>
			<tr>";
			foreach ($tach_name as $data_name) {
				echo "<td>$data_name</td>";
			}
			echo "</tr></table>";
		}
	}
	if ($check_name == 0) {
		echo "<h3>Not Found</h3>";
	}
}

fclose($myfile);



?>
<style type="text/css">
	table,
	td,
	tr {
		border: 0.5px solid black;
		border-collapse: collapse;
	}

	#stt,
	#stt_max,
	#stt_min {
		width: 20px;
		text-align: center;
	}

	#name,
	#name_max,
	#name_min {
		width: 170px;
	}

	#birth,
	#birth_max,
	#birth_min {
		width: 80px;
		text-align: center;
	}

	#avgmark,
	#avgmark_max,
	#avgmark_min {
		width: 28px;
		text-align: center;
	}

	#finddata {
		display: inline-block;
	}

	#avgmark_max,
	#stt_max,
	#name_max,
	#birth_max {
		background-color: green;

	}

	#avgmark_min,
	#stt_min,
	#name_min,
	#birth_min {
		background-color: red;

	}
</style>