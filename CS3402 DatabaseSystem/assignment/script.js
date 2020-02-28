window.onload = () =>
{
	// makeXMLRequest("getHouse.php?q='houseA'",
	// 	(data)=>{
	// 		console.log(data);
	// 	}
	// );

	// $('#nav-tab a').on('click', function (e) {
	// 	e.preventDefault()
	// 	console.log(this.dataset.house);
	// 	// makeXMLRequest("insertinto.php?q="+this.dataset.house,
	// 	// (data)=>{
	// 	// 	console.log(data);
	// 	// }
	// // );
	// 	$(this).tab('show')
	// })

	
};

function register(house){
	let params = {
		name:'',
		email:'',
		seatNo:'',
		house:house
	};

	params.name = prompt("What is your name?");
	params.email = prompt("What is your email?");
	params.seatNo = prompt("How many seats you want?");
	while (isNaN(params.seatNo) || parseInt(params.seatNo)>10 || parseInt(params.seatNo)<=0){
		params.seatNo = prompt("How many seats you want? Please enter from 1 to 10.");
	}
	params.seatNo = parseInt(params.seatNo);
	var query = $.param(params);
	makeXMLRequest("putOrder.php?"+query,(data)=>{
		// console.log(data);
		// alert("Please reload the page");
			window.location.replace("https://cs3402.cs.cityu.edu.hk/~zhlow2/assignment/index.php"+data);
	})
	// console.log("putOrder.php?"+query);
}


function makeXMLRequest(query,callback){
	var xmlhttp = new XMLHttpRequest();
	xmlhttp.onreadystatechange = function ()
	{
		if (this.readyState == 4 && this.status == 200)
		{
			console.log(this.responseText);
			callback(this.responseText);
		}

	};
	xmlhttp.open("GET",query, true);
	xmlhttp.send();
}


