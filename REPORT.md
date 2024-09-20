# Report

This report will be converted into PDF format later on.

## Insights
- Single string assembly index is $\lceil \log_2(n) \rceil$
- Max outer loops (global time) for string assembly is also $\lceil \log_2(n) \rceil$
- If you keep track of the index at each string, you can backtrack from $\lceil \log_2(n) \rceil - 1$ since you know automatically that the last will combine + 1 to get the solution. I wonder if you could recursively apply this to somehow save a shit ton of computation?
- If you constrain the possible assemblies to be a substring of the end result, it drastically reduces computation.  By how much? Not sure. 
- Guess: Applying monte carlo search or heuristics leads to wrong solutions, but approximately good.
- there could be other ways to constrain the possibilities and still get accurate results? There also may be heuristics that don't mess with the final result. 
- I could either backtrack the results or I could construct a graph and the objects contain a node instead of the combined string. The memory savings would be BIG though. 
- Backtracking idea if low on memory
	- Compute up to $\lceil \log_2(n) \rceil - 1$ and keep track of current best assembly index for each object
	- Find the two smallest objects that combine to get the result at $\lceil \log_2(n) \rceil$
	- This will recover a+b->c where c is the end result. Repeat this by subtract 1 to recover the entire tree.
- If low on compute
	- Add a node and its assembly index
	- When you combine nodes, point to the nodes and sum their assembly index + 1
	- Stop at $\lceil \log_2(n) \rceil - 1$ and do backtracking just for one layer to recover the last connection
- Idea: forward in one thread, backtrack in another, do monte-carlo search in both directions.


## Cite

```bibtex
@misc{bertucci2024fast,
      title={Fast String Assembly}, 
      author={Donald Bertucci},
      year={2024},
      url={https://github.com/xnought/fast-string-assembly}, 
}
```