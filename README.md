# Fast String Assembly

Assembly Theory index approximation on longer strings. Example: protein sequence and 3Di sequence assembly computation.

**Problem 1**: Computing the Assembly Index is super exponential. Roughly $O(n^n)$ computations and memory in the worst case.

Can we approximate Assembly Theory or massively speed up the computation?

Probably?

**Problem 2**: once we have a large tree that defined the assembly index, how can we visualize this?

I'm thinking a hierarchical tree where sections are hidden and can be expanded. Use something like https://apple.github.io/ml-mycelium/getting-started/

**Who are these solutions helping?** 

1. Assembly Theory Researchers (visualize their results and actually compute string results)
2. People filtering and searching proteins with a complexity metric
3. A way to compute on long strings so we can compare AT to other complexity metrics or information theoretic ideas.


**Output**

1. Paper explaining the ideas and what worked and did not
2. A Python interface to run Assembly Theory on strings 
3. Code that executes in polynomial time and is lighting fast (very scientific indeed)
4. A visual representation output of the result in a notebook or returned as a website (HTML)

## Cite

```bibtex
@misc{bertucci2024fast,
      title={Fast String Assembly}, 
      author={Donald Bertucci},
      year={2024},
      url={https://github.com/xnought/fast-string-assembly}, 
}
```


## References

- https://www.ncbi.nlm.nih.gov/pmc/articles/PMC10567559/
- https://apple.github.io/ml-mycelium/
