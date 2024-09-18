Colsen Murray (No Project Partner)
Dr. Emrich - CS302 - Proj 2
This code takes a list of numbers in arbitrary order as an input. It then 
uses a sorting algorithm and returns the new list. The sorting methods are 
oblivious (none), stl, qsort, quick sort, and merge sort.

GitHub Repo Link:

    https://github.com/ColsenUTK/SortingProject

To generate a file of random numbers, use the following command:
    
    ./generatelist [num ints]

If that doesn't work, precede it with:
    
    g++ -o generatelist generateFiles.cpp


For the times below, I removed the print function from main.cpp. Most of the time taken was 
because of that portion, not the algorithm, so I decided this was more valid in terms of data.

| Mode    |  Size    | Elapsed Time (s)  |
|---------|----------|-------------------|
| STL     | 10       | 0.002             | 
| ...     | 100      | 0.002             | 
| ...     | 1000     | 0.002             | 
| ...     | 10000    | 0.006             | 
| ...     | 100000   | 0.051             | 
| ...     | 1000000  | 0.772             | 
| ...     | 10000000 | 9.883             | 
| Qsort   | 10       | 0.002             | 
| ...     | 100      | 0.002             | 
| ...     | 1000     | 0.002             | 
| ...     | 10000    | 0.004             | 
| ...     | 100000   | 0.033             | 
| ...     | 1000000  | 0.458             | 
| ...     | 10000000 | 2.041             | 
| Merge   | 10       | 0.002             | 
| ...     | 100      | 0.002             | 
| ...     | 1000     | 0.002             | 
| ...     | 10000    | 0.005             | 
| ...     | 100000   | 0.037             | 
| ...     | 1000000  | 0.573             | 
| ...     | 10000000 | 8.078             | 
| Quick   | 10       | 0.002             | 
| ...     | 100      | 0.001             | 
| ...     | 1000     | 0.001             | 
| ...     | 10000    | 0.005             |         
| ...     | 100000   | 0.046             | 
| ...     | 1000000  | 0.938             | 
| ...     | 10000000 | 15.180            | 


Somewhat unsuprisingly, the stl functions both outperformed or performed similarly to my functions. STL sort wasn't abnormally fast, as it was similar in time to my Merge sort function. Quick sort did not live up to its name, taking the longest of all. On the other hand, Qsort was the fastest algorithm by a long shot, and it implements the quicksort algorithm. As we discussed in class, this is due to the disparity in pivot points. My implementation is probably performing closer to the O(n^2) worst case than the O(nlogn) average case. All of these times were longer than their theoretical values due to execution time. I think that a properly implemented quicksort is probably the best. In this table, it was blazing fast compared to the other algorithms. While the time complexity can be bad at worst case, a proper implementation fixes that fault through smart pivot placement. 
