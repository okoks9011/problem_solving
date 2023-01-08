package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"sort"
)

var in = bufio.NewReader(os.Stdin)

type moment struct {
	idx, t int
}

type day struct {
	id       int
	possible int
}

type dayHeap []day

func (d dayHeap) Len() int           { return len(d) }
func (d dayHeap) Less(i, j int) bool { return d[i].possible < d[j].possible }
func (d dayHeap) Swap(i, j int)      { d[i], d[j] = d[j], d[i] }

func (d *dayHeap) Push(x any) {
	*d = append(*d, x.(day))
}

func (d *dayHeap) Pop() any {
	old := *d
	n := len(old)
	x := old[n-1]
	*d = old[0 : n-1]
	return x
}

func main() {
	var n, m, d int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)
	fmt.Fscan(in, &d)

	a := make([]moment, n)
	for i := range a {
		a[i].idx = i
		fmt.Fscan(in, &a[i].t)
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i].t < a[j].t
	})

	last := 1
	dh := &dayHeap{}
	alloc := make([]int, n)

	heap.Push(dh, day{last, a[0].t + d})
	alloc[a[0].idx] = last
	last++

	for i := 1; i < n; i++ {
		var curDay day
		if (*dh)[0].possible < a[i].t {
			curDay = heap.Pop(dh).(day)
		} else {
			curDay = day{last, 0}
			last++
		}
		curDay.possible = a[i].t + d
		alloc[a[i].idx] = curDay.id
		heap.Push(dh, curDay)
	}
	fmt.Println(last - 1)
	for _, allocI := range alloc {
		fmt.Printf("%d ", allocI)
	}
	fmt.Println()
}
