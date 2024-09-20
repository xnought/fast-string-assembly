<script>
	import AssemblyGraph from "./lib/AssemblyGraph.svelte";
	import { fastStringAssembly } from "./lib/fsa";
	let str = "abracadabra";
	console.time("fsa");
	const out = fastStringAssembly(str);
	console.timeEnd("fsa");
</script>

<main>
	<h1>{str}</h1>
	<div style="outline: 1px solid grey;">
		<AssemblyGraph />
	</div>
</main>

<style>
</style>
