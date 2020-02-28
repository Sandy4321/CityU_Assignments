<?php

$q = $_REQUEST["q"];
$loadTo = 'A';
$loadTo = $_REQUEST["loadTo"];

print "<!DOCTYPE html>
<html lang='en'>

<head>
    <meta charset='UTF-8'>
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>
    <meta http-equiv='X-UA-Compatible' content='ie=edge'>
    <title>Database System Homework</title>

    <script src='https://code.jquery.com/jquery-3.3.1.slim.min.js'
        integrity='sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo' crossorigin='anonymous'>
    </script>
    <script src='https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js'
        integrity='sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1' crossorigin='anonymous'>
    </script>
    <link rel='stylesheet' href='https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css'
        integrity='sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T' crossorigin='anonymous'>
    <script src='https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js'
        integrity='sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM' crossorigin='anonymous'>
    </script>

    <link rel='stylesheet' href='style.css'>
    <script src='script.js'></script>
</head>
<body>
    <div class='container m-5'>
    </div>
    <div class=' jumbotron'>
        <div class='container ml-5'>
			<h1>CS 3402 Assignment</h1>";
if ($q !== null){
	print "<h2 style='color:pink' >".$q."</h2>";
}
	print	"
        </div>
    </div>

    <div class='container'>
        <nav>
			<div class='nav nav-tabs' id='nav-tab' role='tablist'>";
		
	if ($loadTo == null){
		$loadTo = 'A';
	}
	for ($p = A;$p<='E';$p++){
		print " <a class='nav-item nav-link ";
		if ($loadTo == $p){
			print "active";
		}
		print "' id='nav-home-tab' data-toggle='tab' data-house='houseA' href='#nav-house".$p."' role='tab'
		aria-controls='nav-house".$p."' aria-selected='true'>House ".$p."</a>";
	}
                // <a class='nav-item nav-link active' id='nav-home-tab' data-toggle='tab' data-house='houseA' href='#nav-houseA' role='tab'
                //     aria-controls='nav-houseA' aria-selected='true'>House A</a>
                // <a class='nav-item nav-link' id='nav-profile-tab' data-toggle='tab' data-house='houseB' href='#nav-houseB' role='tab'
                //     aria-controls='nav-houseB' aria-selected='false'>House B</a>
                // <a class='nav-item nav-link' id='nav-contact-tab' data-toggle='tab' data-house='houseC' href='#nav-houseC' role='tab'
                //     aria-controls='nav-houseC' aria-selected='false'>House C</a>
                // <a class='nav-item nav-link' id='nav-contact-tab' data-toggle='tab' data-house='houseD'  href='#nav-houseD' role='tab'
                //     aria-controls='nav-houseD' aria-selected='false'>House D</a>
                // <a class='nav-item nav-link' id='nav-contact-tab' data-toggle='tab' data-house='houseE' href='#nav-houseE' role='tab'
                //     aria-controls='nav-houseE' aria-selected='false'>House E</a>
    print "</div>
		</nav>
		<div class='tab-content text-light' id='nav-tabContent'>";
// print "
//             <div class='tab-pane fade show active' id='nav-houseA' role='tabpanel' aria-labelledby='nav-home-tab'>
//                 <div class='d-flex justify-content-center'>
//                     <table class='table-light'>
//                         <tbody>
//                             <tr>
//                                 <td>A0</td>
//                                 <td>A1</td>
//                                 <td>A2</td>
//                                 <td>A3</td>
//                                 <td>A4</td>
//                                 <td>A5</td>
//                                 <td>A6</td>
//                                 <td>A7</td>
//                                 <td>A8</td>
//                                 <td>A9</td>
//                             </tr>
//                             <tr>
//                                 <td>B0</td>
//                                 <td>B1</td>
//                                 <td>B2</td>
//                                 <td>B3</td>
//                                 <td>B4</td>
//                                 <td>B5</td>
//                                 <td>B6</td>
//                                 <td>B7</td>
//                                 <td>B8</td>
//                                 <td>B9</td>
//                             </tr>
//                             <tr>
//                                 <td>C0</td>
//                                 <td>C1</td>
//                                 <td>C2</td>
//                                 <td>C3</td>
//                                 <td>C4</td>
//                                 <td>C5</td>
//                                 <td>C6</td>
//                                 <td>C7</td>
//                                 <td>C8</td>
//                                 <td>C9</td>
//                             </tr>
//                             <tr>
//                                 <td>D0</td>
//                                 <td>D1</td>
//                                 <td>D2</td>
//                                 <td>D3</td>
//                                 <td>D4</td>
//                                 <td>D5</td>
//                                 <td>D6</td>
//                                 <td>D7</td>
//                                 <td>D8</td>
//                                 <td>D9</td>
//                             </tr>
//                             <tr>
//                                 <td>E0</td>
//                                 <td>E1</td>
//                                 <td>E2</td>
//                                 <td>E3</td>
//                                 <td>E4</td>
//                                 <td>E5</td>
//                                 <td>E6</td>
//                                 <td>E7</td>
//                                 <td>E8</td>
//                                 <td>E9</td>
//                             </tr>
//                         </tbody>
//                     </table>
//                 </div>
//             </div>"."
//             <div class='tab-pane fade' id='nav-houseB' role='tabpanel' aria-labelledby='nav-profile-tab'>
//                 <div class='d-flex justify-content-center'><table class='table-light'>
//                         <tbody>
//                             <tr>
//                                 <td>A0</td>
//                                 <td>A1</td>
//                                 <td>A2</td>
//                                 <td>A3</td>
//                                 <td>A4</td>
//                                 <td>A5</td>
//                                 <td>A6</td>
//                                 <td>A7</td>
//                                 <td>A8</td>
//                                 <td>A9</td>
//                             </tr>
//                             <tr>
//                                 <td>B0</td>
//                                 <td>B1</td>
//                                 <td>B2</td>
//                                 <td>B3</td>
//                                 <td>B4</td>
//                                 <td>B5</td>
//                                 <td>B6</td>
//                                 <td>B7</td>
//                                 <td>B8</td>
//                                 <td>B9</td>
//                             </tr>
//                             <tr>
//                                 <td>C0</td>
//                                 <td>C1</td>
//                                 <td>C2</td>
//                                 <td>C3</td>
//                                 <td>C4</td>
//                                 <td>C5</td>
//                                 <td>C6</td>
//                                 <td>C7</td>
//                                 <td>C8</td>
//                                 <td>C9</td>
//                             </tr>
//                             <tr>
//                                 <td>D0</td>
//                                 <td>D1</td>
//                                 <td>D2</td>
//                                 <td>D3</td>
//                                 <td>D4</td>
//                                 <td>D5</td>
//                                 <td>D6</td>
//                                 <td>D7</td>
//                                 <td>D8</td>
//                                 <td>D9</td>
//                             </tr>
//                             <tr>
//                                 <td>E0</td>
//                                 <td>E1</td>
//                                 <td>E2</td>
//                                 <td>E3</td>
//                                 <td>E4</td>
//                                 <td>E5</td>
//                                 <td>E6</td>
//                                 <td>E7</td>
//                                 <td>E8</td>
//                                 <td>E9</td>
//                             </tr>
//                         </tbody>
//                     </table></div>
//             </div>
//             <div class='tab-pane fade' id='nav-houseC' role='tabpanel' aria-labelledby='nav-contact-tab'>
//                 <div class='d-flex justify-content-center'><table class='table-light'>
//                         <tbody>
//                             <tr>
//                                 <td>A0</td>
//                                 <td>A1</td>
//                                 <td>A2</td>
//                                 <td>A3</td>
//                                 <td>A4</td>
//                                 <td>A5</td>
//                                 <td>A6</td>
//                                 <td>A7</td>
//                                 <td>A8</td>
//                                 <td>A9</td>
//                             </tr>
//                             <tr>
//                                 <td>B0</td>
//                                 <td>B1</td>
//                                 <td>B2</td>
//                                 <td>B3</td>
//                                 <td>B4</td>
//                                 <td>B5</td>
//                                 <td>B6</td>
//                                 <td>B7</td>
//                                 <td>B8</td>
//                                 <td>B9</td>
//                             </tr>
//                             <tr>
//                                 <td>C0</td>
//                                 <td>C1</td>
//                                 <td>C2</td>
//                                 <td>C3</td>
//                                 <td>C4</td>
//                                 <td>C5</td>
//                                 <td>C6</td>
//                                 <td>C7</td>
//                                 <td>C8</td>
//                                 <td>C9</td>
//                             </tr>
//                             <tr>
//                                 <td>D0</td>
//                                 <td>D1</td>
//                                 <td>D2</td>
//                                 <td>D3</td>
//                                 <td>D4</td>
//                                 <td>D5</td>
//                                 <td>D6</td>
//                                 <td>D7</td>
//                                 <td>D8</td>
//                                 <td>D9</td>
//                             </tr>
//                             <tr>
//                                 <td>E0</td>
//                                 <td>E1</td>
//                                 <td>E2</td>
//                                 <td>E3</td>
//                                 <td>E4</td>
//                                 <td>E5</td>
//                                 <td>E6</td>
//                                 <td>E7</td>
//                                 <td>E8</td>
//                                 <td>E9</td>
//                             </tr>
//                         </tbody>
//                     </table></div>
//             </div>
//             <div class='tab-pane fade' id='nav-houseD' role='tabpanel' aria-labelledby='nav-contact-tab'>
//                 <div class='d-flex justify-content-center'><table class='table-light'>
//                         <tbody>
//                             <tr>
//                                 <td>A0</td>
//                                 <td>A1</td>
//                                 <td>A2</td>
//                                 <td>A3</td>
//                                 <td>A4</td>
//                                 <td>A5</td>
//                                 <td>A6</td>
//                                 <td>A7</td>
//                                 <td>A8</td>
//                                 <td>A9</td>
//                             </tr>
//                             <tr>
//                                 <td>B0</td>
//                                 <td>B1</td>
//                                 <td>B2</td>
//                                 <td>B3</td>
//                                 <td>B4</td>
//                                 <td>B5</td>
//                                 <td>B6</td>
//                                 <td>B7</td>
//                                 <td>B8</td>
//                                 <td>B9</td>
//                             </tr>
//                             <tr>
//                                 <td>C0</td>
//                                 <td>C1</td>
//                                 <td>C2</td>
//                                 <td>C3</td>
//                                 <td>C4</td>
//                                 <td>C5</td>
//                                 <td>C6</td>
//                                 <td>C7</td>
//                                 <td>C8</td>
//                                 <td>C9</td>
//                             </tr>
//                             <tr>
//                                 <td>D0</td>
//                                 <td>D1</td>
//                                 <td>D2</td>
//                                 <td>D3</td>
//                                 <td>D4</td>
//                                 <td>D5</td>
//                                 <td>D6</td>
//                                 <td>D7</td>
//                                 <td>D8</td>
//                                 <td>D9</td>
//                             </tr>
//                             <tr>
//                                 <td>E0</td>
//                                 <td>E1</td>
//                                 <td>E2</td>
//                                 <td>E3</td>
//                                 <td>E4</td>
//                                 <td>E5</td>
//                                 <td>E6</td>
//                                 <td>E7</td>
//                                 <td>E8</td>
//                                 <td>E9</td>
//                             </tr>
//                         </tbody>
//                     </table></div>
//             </div>
//             <div class='tab-pane fade' id='nav-houseE' role='tabpanel' aria-labelledby='nav-contact-tab'>
//                 <div class='d-flex justify-content-center'><table class='table-light'>
//                         <tbody>
//                             <tr>
//                                 <td>A0</td>
//                                 <td>A1</td>
//                                 <td>A2</td>
//                                 <td>A3</td>
//                                 <td>A4</td>
//                                 <td>A5</td>
//                                 <td>A6</td>
//                                 <td>A7</td>
//                                 <td>A8</td>
//                                 <td>A9</td>
//                             </tr>
//                             <tr>
//                                 <td>B0</td>
//                                 <td>B1</td>
//                                 <td>B2</td>
//                                 <td>B3</td>
//                                 <td>B4</td>
//                                 <td>B5</td>
//                                 <td>B6</td>
//                                 <td>B7</td>
//                                 <td>B8</td>
//                                 <td>B9</td>
//                             </tr>
//                             <tr>
//                                 <td>C0</td>
//                                 <td>C1</td>
//                                 <td>C2</td>
//                                 <td>C3</td>
//                                 <td>C4</td>
//                                 <td>C5</td>
//                                 <td>C6</td>
//                                 <td>C7</td>
//                                 <td>C8</td>
//                                 <td>C9</td>
//                             </tr>
//                             <tr>
//                                 <td>D0</td>
//                                 <td>D1</td>
//                                 <td>D2</td>
//                                 <td>D3</td>
//                                 <td>D4</td>
//                                 <td>D5</td>
//                                 <td>D6</td>
//                                 <td>D7</td>
//                                 <td>D8</td>
//                                 <td>D9</td>
//                             </tr>
//                             <tr>
//                                 <td>E0</td>
//                                 <td>E1</td>
//                                 <td>E2</td>
//                                 <td>E3</td>
//                                 <td>E4</td>
//                                 <td>E5</td>
//                                 <td>E6</td>
//                                 <td>E7</td>
//                                 <td>E8</td>
//                                 <td>E9</td>
//                             </tr>
//                         </tbody>
//                     </table></div>
//             </div>
//         </div>";
$conn = oci_connect("zhlow2", "54924670", "//ora11g.cs.cityu.edu.hk:1522/orcl.cs.cityu.edu.hk");
if (!$conn) {
	$m = oci_error();
	$error = [
		"Error" => $m['message']
	];
	echo json_encode($error);
	exit;
}


function executeCommand($command, $conn)
{
	$stid = oci_parse($conn, $command);
	if (!$stid) {
		$e = oci_error($conn);
		trigger_error(json_encode($e['message']), E_USER_ERROR);
	}

	// Perform the logic of the query
	$r = oci_execute($stid);
	if (!$r) {
		$e = oci_error($stid);
		trigger_error(json_encode($e['message']), E_USER_ERROR);
	}
	return $stid;
}




$responseObj = [];

if ($loadTo == null){
	$loadTo == 'A';
}
for ($i = 'A'; $i <= 'E'; $i++) {
	$responseObj = [];
	$stid = executeCommand("SELECT * FROM ORDERS WHERE HOUSE='" . $i . "'", $conn);
	while ($row = oci_fetch_array($stid, OCI_ASSOC + OCI_RETURN_NULLS)) {
		$responseObj[] = $row;
	}
	print "<div class='tab-pane fade show ";
	
	if ($i == $loadTo){
		print "active";
		
	}
	print "' id='nav-house".$i."' role='tabpanel' aria-labelledby='nav-home-tab'>
		<div class='d-flex justify-content-center'>
		<table class='table-light'>
			<tbody>
				";

	for ($j = 'A'; $j <= 'E'; $j++) {
		print "<tr> ";
		for ($k = 0; $k < 10; $k++) {
			$existIn = false;
			foreach ($responseObj as $item) {
				if ($item['SEAT_ROW'] == $j && $item['SEAT_COL'] == $k) {
					$existIn = true;
					break;
				}
			}
			print "<td ";
			if ($existIn) {
				print "class='occupied'";
			};
			print ">" . $j . $k."</td>";
		}
		print "</tr>";
	}
	print "
	</tbody>
</table>

</div>
<div class='d-flex justify-content-center'>
<a class='m-3' href='./removeAll.php?q=" . $i . "'><button class='btn btn-dark' >Remove All</button></a>
<button class='m-3 btn btn-dark' onclick='register(\"" . $i . "\")'>Register</button>
</div>
</div>";
}





print "
</div>
</body>
</html>";



oci_close($conn);
