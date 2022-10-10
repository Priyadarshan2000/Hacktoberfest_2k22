console.log('Welcome to notes app.This is app.js')
showNotes();
//if user adds a note, add it to the localstorage

let addBtn= document.getElementById('addBtn');
addBtn.addEventListener("click",function(e){
	let addTxt = document.getElementById("addTxt");
	let notes = localStorage.getItem("notes");
	if(notes == null){
		notesObj = [];
	}
	else{
		notesObj = JSON.parse(notes);
	}
	notesObj.push(addTxt.value);
	localStorage.setItem("notes",JSON.stringify(notesObj));
	addTxt.value =  "";
	//console.log(notesObj);
	showNotes();
})

	//function to show elements--------

function showNotes(){
	let notes = localStorage.getItem("notes");
	if(notes == null){
		notesObj = [];
	}
	else{
		notesObj = JSON.parse(notes);
	}
	let html ="";
	notesObj.forEach(function(element,index){
		html+= `
				<div class="noteCard my-2 mx-2 card" style="width: 18rem;">
  					<div class="card-body">
    					<h5 class="card-title">Note ${index + 1}</h5>
    					<p class="card-text">${element}</p>
    					<button id="${index}" onclick="deleteNote(this.id)" class="btn btn-dark ">Delete Notes</button>
  					</div>
				</div>

				`;
				

	});

	let notesElm = document.getElementById('notes');
	if(notesObj.length!=0){
		notesElm.innerHTML = html;
	}
	else{
		notesElm.innerHTML = `Nothing to show. Use "Add Note" section above to add notes.`;

	}
}


	//function to delte a note-------

function deleteNote(index){
	//console.log('I am deleting',index);
	let notes = localStorage.getItem("notes");
	if(notes == null){
		notesObj = [];
	}
	else {
		notesObj = JSON.parse(notes);
	}
	notesObj.splice(index,1);
	localStorage.setItem("notes",JSON.stringify(notesObj));
	showNotes();
}
	let search = document.getElementById('searchTxt');
	search.addEventListener("input",function(){
		let inputval= search.value.toLowerCase();
		//console.log('Input event fired',inputval);
		let noteCards = document.getElementsByClassName('noteCard');
		Array.from(noteCards).forEach(function(element){
			let cardTxt = element.getElementsByTagName("p")[0].innerText;
			if(cardTxt.includes(inputval)){
				element.style.display = "block";
			}
			else{
				element.style.display = "none";
			}
		})
	})
