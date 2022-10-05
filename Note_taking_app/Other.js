//console.log('a')
const addbtn =document.querySelector("#addbtn")
const main= document.querySelector("#main")
addbtn.addEventListener(
    "click",
    function() {
        addNote()
    }
)


const saveNotes = () => {
    const notes = document.querySelectorAll(".note textarea");
    console.log(notes);
    const data =[];
    notes.forEach(
        (note) => {
            data.push(note.value)
        }
    )
    //console.log(data);
    //Keeping the values to the local storage
    localStorage.setItem("notes", JSON.stringify(data))
}



 


/*<div class="note">
            <div class="tool">
                <i class="fa-solid fa-floppy-disk"></i>
                <i class="fa-solid fa-trash-can"></i>
                
            </div>
            <textarea></textarea>
        
        
    </div>
   */


const addNote= (text = "") =>{
    const note= document.createElement("div");
    note.classList.add("note");
    note.innerHTML =`
    <div class="tool"> 
                <i class="save fa-solid fa-floppy-disk"></i>
                <i class="trash fa-solid fa-trash-can"></i>
                
            </div>
            <textarea>${text}</textarea>
        `;

        note.querySelector(".trash").addEventListener(
            "click",
            function (){
                note.remove();
            }
        )
        note.querySelector(".save").addEventListener(
            "click",
            function(){
                saveNotes();
            }
        )
        main.appendChild(note);
        saveNotes()
}
//Though the page is reloaded the contents will be shown
(
    function(){
        const isNotes =JSON.parse( localStorage.getItem("notes"));
        if (isNotes === null) {
            addNote()
        } else {
            isNotes.forEach(
                (isNotes) => {
                    addNote(isNotes)
                }
            )
        }

    }
)()
