const arr = [];

const push_stack = (ele) => {
	arr.push(ele);
};

const pop_stack = () => {
	if (arr.length !== 0) {
		const x = arr[arr.length - 1];
		arr.pop();
		return x;
	} else console.log("stack underflow");
};

const stack_size = () => {
	return arr.length;
};

const stack_is_empty = () => {
	return arr.length === 0;
};

const display_ele = () => {
	while (arr.length !== 0) {
		let ele = arr[arr.length - 1];
		console.log(ele);
		arr.pop();
	}
};

push_stack(22);
push_stack(32);
push_stack(42);
push_stack(52);
push_stack(62);
push_stack(72);

console.log(stack_size()); // output:-  6

let poped_ele = pop_stack();

console.log(poped_ele); // output:- 72

console.log(stack_size()); // output:- 5

console.log(stack_is_empty()); // false

display_ele();

console.log(stack_size()); // 0

console.log(stack_is_empty()); // true
