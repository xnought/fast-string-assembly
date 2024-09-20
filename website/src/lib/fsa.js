export let LOG_SET = true;
export let LOG_T = true;

/**
 * @param {string} str
 */
function preprocess(str) {
	return str.toLowerCase();
}

/**
 * @param {string} str
 */
function atomize(str) {
	const atoms = new Set();
	for (let i = 0; i < str.length; i++) {
		atoms.add(str[i]);
	}
	return atoms;
}

/**
 * @param {string} str
 * @param {string} object
 */
function keepObject(str, object) {
	return object.length <= str.length && str.indexOf(object) != -1;
}

/**
 *
 * @param {string} str
 * @param {Set<string>} objects
 */
function assemble(str, objects) {
	let solFound = false;
	const newObjects = new Set();
	outer: for (const o1 of objects) {
		for (const o2 of objects) {
			const no = o1 + o2;
			if (keepObject(str, no)) {
				newObjects.add(no);
			}
			if (no == str) {
				solFound = true;
				break outer;
			}
		}
	}
	for (const o of newObjects) {
		objects.add(o);
	}
	return solFound;
}

/**
 *
 * @param {Set} s
 * @param {number} t
 */
function logObjects(s, t) {
	if (LOG_T) {
		console.log(`t=${t}, len(o)=${s.size} `);
	}
	if (LOG_SET) {
		let out = "";
		for (const o of s) {
			out += `${o} `;
		}
		console.log(out);
		console.log("");
	}
}

/**
 * @param {string} str
 */
export function fastStringAssembly(str) {
	str = preprocess(str);
	let atoms = atomize(str);
	let t = 0;
	let objects = atoms;
	logObjects(objects, t);
	let sol = assemble(str, objects);
	logObjects(objects, ++t);
	while (!sol) {
		sol = assemble(str, objects);
		logObjects(objects, ++t);
	}
	return str;
}
