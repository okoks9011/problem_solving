package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(in, &n)

	given := make([]bool, n)
	friends := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &friends[i])
		if friends[i] != 0 {
			given[friends[i]-1] = true
		}
	}

	notGive := make(map[int]bool)
	give := make(map[int]bool)
	for i, v := range given {
		if v {
			continue
		}
		if friends[i] == 0 {
			notGive[i] = true
		} else {
			give[i] = true
		}
	}

	for i := range friends {
		if friends[i] != 0 {
			continue
		}

		candi := -1
		for k := range notGive {
			if k != i {
				candi = k
				break
			}
		}
		if candi != -1 {
			friends[i] = candi + 1
			delete(notGive, candi)
			if _, ok := notGive[i]; ok {
				delete(notGive, i)
				give[i] = true
			}
			continue
		}

		for k := range give {
			candi = k
			break
		}
		friends[i] = candi + 1
		delete(give, candi)
		if _, ok := notGive[i]; ok {
			delete(notGive, i)
			give[i] = true
		}
	}
	for _, v := range friends {
		fmt.Print(v, " ")
	}
	fmt.Println()
}
