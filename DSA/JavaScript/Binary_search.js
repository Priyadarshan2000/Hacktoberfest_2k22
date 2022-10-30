const bin_Search = (arr, n, ele) => {
	let start = arr[0];
	let end = arr[n - 1];

	while (start <= end) {
		let mid = Math.floor((start + end) / 2);

		if (arr[mid] == ele) {
			return true;
		} else if (arr[mid] < ele) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	return false;
};

const element_found_or_not = (ans) => {
	if (ans) {
		console.log("Element is found");
	} else {
		console.log("Element is not found");
	}
};

const arr = [1, 2, 3, 4, 5];

const n = arr.length;
let ans = bin_Search(arr, n, 5);

element_found_or_not(ans); // Element is found

ans = bin_Search(arr, n, 66);
element_found_or_not(ans); // Element is not found
