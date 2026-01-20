// BUTTON EVENTS
const onClickBtn = document.querySelector("#Btn1");
const onLoadBtn = document.querySelector("#Btn2");
const myForm = document.querySelector("#myForm");

// Load event
window.addEventListener("load", () => {
    onLoadBtn.textContent = "Page Loaded";
    onLoadBtn.style.backgroundColor = "lightgreen";
    onLoadBtn.style.color = "black";
});

// Click event
onClickBtn.addEventListener("click", () => {
    onClickBtn.classList.toggle("colorChange");
});

// Form reset
/*myForm.addEventListener("reset", () => {
    alert("Form reset!");
});*/

// Form submit
myForm.addEventListener("submit", (event) => {
    event.preventDefault();
    alert("form submitted");
});

// TEXT EVENTS
const textBox = document.querySelector("#textBox");
const selectInput = document.querySelector("#selectInput");
const focusInput = document.querySelector("#focusInput");

// onchange
textBox.addEventListener("change", () => {
    alert("Text changed to: " + textBox.value);
});

// onselect
selectInput.addEventListener("select", () => {
    alert("You selected text!");
});

// onfocus / onblur
focusInput.addEventListener("focus", () => {
    focusInput.style.backgroundColor = "yellow";
});
focusInput.addEventListener("blur", () => {
    focusInput.style.backgroundColor = "red";
});

// MOUSE EVENTS
const mouse1 = document.querySelector("#Mouse1");
const mouse2 = document.querySelector("#Mouse2");
const mouse3 = document.querySelector("#Mouse3");

mouse1.addEventListener("mouseover", () => {
    mouse1.textContent = "Mouse Over Detected!";
});
mouse2.addEventListener("mouseout", () => {
    mouse2.textContent = "Mouse Out!";
});
mouse3.addEventListener("mousemove", () => {
    mouse3.classList.toggle("colorChange");
});

// KEYBOARD EVENTS
const key1 = document.querySelector("#keyboard1");
const key2 = document.querySelector("#keyboard2");
const key3 = document.querySelector("#keyboard3");

document.addEventListener("keydown", (e) => {
    key1.textContent = "key down: " + e.key;
});
document.addEventListener("keyup", (e) => {
    key2.textContent = "key up: " + e.key;
});
document.addEventListener("keypress", (e) => {
    key3.textContent = "key press: " + e.key;
});

// EVENT BUBBLING
const grandpa = document.querySelector("#grandparent");
const par = document.querySelector("#parent");
const chld = document.querySelector("#child");

grandpa.addEventListener("click", () => {
    
    grandpa.style.backgroundColor = "yellow";
});
par.addEventListener("click", () => {
    par.style.backgroundColor = "red";
});
chld.addEventListener("click", () => {
    chld.style.backgroundColor = "white";
});
