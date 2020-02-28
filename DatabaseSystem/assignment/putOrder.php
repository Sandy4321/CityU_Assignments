<?php
$name = $_REQUEST["name"];
$email = $_REQUEST["email"];
$seatNo = $_REQUEST["seatNo"];
$house = $_REQUEST["house"];

$conn = oci_connect("zhlow2", "54924670", "//ora11g.cs.cityu.edu.hk:1522/orcl.cs.cityu.edu.hk");
if (!$conn) {
	$m = oci_error();
	echo '"Error":"', htmlentities($m['message']), '"}';
	exit;
}

function executeCommand($command, $conn)
{
	$stid = oci_parse($conn, $command);
	if (!$stid) {
		$e = oci_error($conn);
		trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
	}

	// Perform the logic of the query
	$r = oci_execute($stid);
	if (!$r) {
		$e = oci_error($stid);
		trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
	}
	return $stid;
}

$q = null;

if ($seatNo > 10 && $seatNo <= 0) {
	$q = "Please input 1 to 10 seats";
} else {

	// SEARCH FROM USER BASE FIRST
	
	$stid = executeCommand("SELECT * FROM CUSTOMER WHERE EMAIL='" . $email . "'", $conn);
	$row = oci_fetch_array($stid, OCI_ASSOC + OCI_RETURN_NULLS);
	if ($row) {
		$q = "Email have already been used please use another email.";
	} else {
		if ($row !== null) {
			$stid = executeCommand("INSERT INTO CUSTOMER VALUES ('" . $email . "','" . $name . "')", $conn);
		}
		// GET ALL THE SEAT IN CINEMA AND SORT BY ROW;
		$stid = executeCommand("SELECT SEAT_ROW, COUNT(SEAT_COL) FROM ORDERS WHERE HOUSE='" . $house . "' GROUP BY SEAT_ROW ORDER BY SEAT_ROW", $conn);
		$responseObj = [];
		while ($row = oci_fetch_array($stid, OCI_ASSOC + OCI_RETURN_NULLS)) {
			$responseObj[] = $row;
		}

		$haveSpace = false;
		$rowChar = 'A';
		$colIndex = 0;
		foreach ($responseObj as $item) {
			if ($item['SEAT_ROW'] != $rowChar) {
				$colIndex = 0;
				$haveSpace = true;
				break;
			} // because it is sorted
			if ((10 - $item["COUNT(SEAT_COL)"]) >= $seatNo) {
				$haveSpace = true;
				$colIndex = $item["COUNT(SEAT_COL)"];
				break;
			}
			$rowChar++;
		}
		if (!$haveSpace && count($responseObj) < 5) {
			$haveSpace = true;
			$colIndex = 0;
		}

		if ($haveSpace) { 
			while ($seatNo > 0){
				$stid = executeCommand("INSERT INTO ORDERS VALUES('".$email."','".$house."','".$rowChar."','".$colIndex."')", $conn);
				$colIndex++;
				$seatNo--;
			}
			
		} else {
			$q = "Sorry we don't have enough space. ";
		}
	}
}


if ($q == null){
	print "?loadTo=".$house;
}else{
	print "?loadTo=".$house."&q=".$q;

}

// print "wtf?";


// if ($q === null) {
	// header("Location: https://cs3402.cs.cityu.edu.hk/~zhlow2/assignment/index.php");
// } else {
	// header("Location: https://cs3402.cs.cityu.edu.hk/~zhlow2/assignment/index.php?q=" . $q);
// }

oci_close($conn);
