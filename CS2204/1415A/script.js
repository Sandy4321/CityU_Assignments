function addBill(object){
	document.querySelector("#tableSelection").style.display = "none";
	document.querySelector("#menuItems").style.display="inline";
	document.querySelector("#food").style.backgroundColor="white";
	document.querySelector("#tables").style.backgroundColor="silver";
	clicked = object;
}
var clicked;
var allMenuItems;

function init(){
	document.querySelector("#table1").ondblclick = function(){addBill(this)};
	document.querySelector("#table2").ondblclick =  function(){addBill(this)};
	document.querySelector("#table3").ondblclick =  function(){addBill(this)};
	document.querySelector("#table4").ondblclick =  function(){addBill(this)};

	allMenuItems = document.querySelectorAll(".menuItem");
	for(var i = 0 ; i < allMenuItems.length ; i ++){
		allMenuItems[i].querySelector('form').onsubmit=function(){return addItem(this);};
	}
	document.querySelector("#tables").onclick =  function(){showTable()};
};

function addItem(menuItems){
	var temp = "";
	if(window.localStorage.getItem(clicked.id) == ""){
		temp +=menuItems.querySelector("input[type='textbox']").value+','+menuItems.querySelector("input[type='number']").value;
	}else{
		temp += window.localStorage.getItem(clicked.id)+'&'+menuItems.querySelector("input[type='textbox']").value+','+menuItems.querySelector("input[type='number']").value;
	}
	window.localStorage.setItem(clicked.id, temp );
	return false;
}

function showTable(){
	document.querySelector("#menuItems").style.display = "none";
	document.querySelector("#tableSelection").style.display="inline";
	document.querySelector("#tables").style.backgroundColor="white";
	document.querySelector("#food").style.backgroundColor="silver";
}