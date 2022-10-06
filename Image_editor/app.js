/*For choosing the image and previewing*/

const fileInput = document.querySelector(".file-input"),
filterOptions = document.querySelectorAll(".filter button");
filterName = document.querySelector(".filter-info .name");
filterValue = document.querySelector(".slider .value");
filterSlider = document.querySelector(".slider input");
rotateOptions = document.querySelectorAll(".rotate button");
previewImg= document.querySelector(".preview-image img");
resetFilterBtn= document.querySelector(".reset-filters");
chooseImgBtn = document.querySelector(".choose-image");
saveImgBtn = document.querySelector(".save-image");

let brightness="100", saturation="100", inversion = "0", grayscale="0";
let rotate = 0, flipHorizontal = 1, flipVertical = 1;

/*const loadImage = () => {
    let file = fileInput.files[0]; //Giving access to the users to select the files
    if(!file) return;//in case the user is failed to upload the image
    previewImg.src = URL.createObjectURL(file)//uploading the image
    previewImg.addEventListener("load", () =>{ 
        document.querySelector(".container").classList.remove("disable");
    });
}*/
const loadImage = () => {
    let file = fileInput.files[0];
    if(!file) return;
    previewImg.src = URL.createObjectURL(file);
    previewImg.addEventListener("load", () => {
        resetFilterBtn.click();
        document.querySelector(".container").classList.remove("disable");
    });
}



const applyFilter = () =>{
    previewImg.style.transform = `rotate(${rotate}deg) scale(${flipHorizontal},${flipVertical })`;//for rotating in a degree
    previewImg.style.filter = `brightness(${brightness}%) saturate(${saturation}%) invert(${inversion}%)  grayscale(${ grayscale}%)`;
}


filterOptions.forEach(Option => {
    Option.addEventListener("click", () =>{
        document.querySelector(".after").classList.remove("after");
        Option.classList.add("after");
        filterName.innerText = Option.innerText;
       
        //Making the individual slider for each filter
        if(Option.id === "brightness") {
            filterSlider.max = "200";
            filterSlider.value = brightness;
            filterValue.innerText = `${brightness}%`;
        } else if(Option.id === "saturation") {
            filterSlider.max = "200";
            filterSlider.value = saturation;
            filterValue.innerText = `${saturation}%`
        } else if(Option.id === "inversion") {
           filterSlider.max = "100";
            filterSlider.value = inversion;
            filterValue.innerText = `${inversion}%`;
        } else {
            filterSlider.max = "100";
            filterSlider.value = grayscale;
            filterValue.innerText = `${grayscale}%`;
        }
    });
});

const updateFilter = () =>{
    filterValue.innerText=`${filterSlider.value}%`;//changing the values of the %
    const selectedFilter = document.querySelector(".filter .after");//selecting the filter

    if(selectedFilter.id === "brightness") {
        brightness = filterSlider.value;
    } else if(selectedFilter.id === "saturation") {
        saturation = filterSlider.value;
    } else if(selectedFilter.id === "inversion") {
        inversion = filterSlider.value;
    } else {
        grayscale = filterSlider.value;
    }
    applyFilter();
}

//code for roation filter

rotateOptions.forEach(Option => {
    Option.addEventListener("click", () => {
        if(Option.id === "left") {//left rotation
            rotate -= 90;
        } else if(Option.id === "right") {//right rotation
            rotate += 90;
        } else if(Option.id === "horizontal") {
            flipHorizontal = flipHorizontal === 1 ? -1 : 1;
        } else {
            flipVertical = flipVertical === 1 ? -1 : 1;
        }
        applyFilter();
    });
});

//functions for reseting the filters
const resetFilter = () => {
    brightness = "100"; saturation = "100"; inversion = "0"; grayscale = "0";
    rotate = 0; flipHorizontal = 1; flipVertical = 1;
    filterOptions[0].click();
    applyFilter();
}
//function for saving the images  after the edit

const saveImage = () => {
    //console.log("saved");
    const canvas = document.createElement("canvas");
    const ctx = canvas.getContext("2d");
    canvas.width = previewImg.naturalWidth;
    canvas.height = previewImg.naturalHeight;
    //applying user selected filtes to canvas filter
    ctx.filter = `brightness(${brightness}%) saturate(${saturation}%) invert(${inversion}%) grayscale(${grayscale}%)`;
    ctx.translate(canvas.width / 2, canvas.height / 2);
    if(rotate !== 0) {
        ctx.rotate(rotate * Math.PI / 180);
    }
    ctx.scale(flipHorizontal, flipVertical);
    ctx.drawImage(previewImg, -canvas.width / 2, -canvas.height / 2, canvas.width, canvas.height);
    
    const link = document.createElement("a");
    link.download = "image.jpg";
    link.href = canvas.toDataURL();
    link.click();
}
filterSlider.addEventListener("input",  updateFilter);
//reseting the filter
resetFilterBtn.addEventListener("click", resetFilter);
//saving the images
saveImgBtn.addEventListener("click", saveImage);
//load the image
fileInput.addEventListener("change", loadImage);
//code for clicking
chooseImgBtn.addEventListener("click", () => fileInput.click());
