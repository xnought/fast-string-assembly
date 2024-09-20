<script>
	import { onMount } from "svelte";
	import * as myc from "@apple/mycelium";
	import "@apple/mycelium/dist/style.css";

	export let height = "800px";
	export let width = "800px";

	let viewer;
	let network;
	let el;
	onMount(() => {
		network = new myc.Network();
		network.setNode("a", createNode("a"));
		network.setNode("b", createNode("b"));
		viewer = myc.NetworkViewer.create(network, el, {
			showBreadcrumbs: true,
			minimap: true,
			watermark: false,
		});
	});

	// given node id produces a node
	function createNode(nodeId) {
		return new myc.ui.Node(
			nodeId,
			new myc.ui.VStack(
				new myc.ui.Text("Object").with({ fontWeight: 600 }),
				new myc.ui.Text(nodeId)
			)
		);
	}
</script>

<div style="width: {width}; height: {height};" bind:this={el}></div>

<style>
</style>
