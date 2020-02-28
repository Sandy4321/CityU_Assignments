<?php
$q = $_REQUEST["q"];

$conn = oci_connect("zhlow2", "54924670", "//ora11g.cs.cityu.edu.hk:1522/orcl.cs.cityu.edu.hk");
if (!$conn) {
	$m = oci_error();
	$error = [
		"Error"=> $m['message']
	];
	echo json_encode($error);
	exit;
} 


function executeCommand($command,$conn){
	$stid = oci_parse($conn, $command);
	if (!$stid) {
		$e = oci_error($conn);
		trigger_error( json_encode($e['message']), E_USER_ERROR);
	}

	// Perform the logic of the query
	$r = oci_execute($stid);
	if (!$r) {
		$e = oci_error($stid);
		trigger_error( json_encode($e['message']), E_USER_ERROR);
	}
	return $stid;
}


$stid = executeCommand("SELECT * FROM SEAT",$conn);
print "<table border='1'>\n";
while ($row = oci_fetch_array($stid, OCI_ASSOC+OCI_RETURN_NULLS)) {
    print "<tr>\n";
    foreach ($row as $item) {
        print "    <td>" . ($item !== null ? htmlentities($item, ENT_QUOTES) : "&nbsp;") . "</td>\n";
    }
    print "</tr>\n";
}
print "</table>\n";


echo  json_encode($responseObj);
// echo "";





oci_close($conn);
