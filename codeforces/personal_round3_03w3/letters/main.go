package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func main() {
	var n int
	fmt.Fscan(in, &n)

	var s, t string
	fmt.Fscan(in, &s)
	fmt.Fscan(in, &t)

	aCnt, bCnt := 0, 0
	var abIdx, baIdx []int
	for i := 0; i < n; i++ {
		si, ti := s[i], t[i]
		if si == 'a' {
			aCnt++
		} else if si == 'b' {
			bCnt++
		} else {
			panic("impossible")
		}
		if ti == 'a' {
			aCnt++
		} else if ti == 'b' {
			bCnt++
		} else {
			panic("impossible")
		}

		if si == 'a' && ti == 'b' {
			abIdx = append(abIdx, i+1)
		} else if si == 'b' && ti == 'a' {
			baIdx = append(baIdx, i+1)
		}
	}
	if aCnt%2 == 1 || bCnt%2 == 1 {
		fmt.Println(-1)
		return
	}
	if len(abIdx)%2 != len(baIdx)%2 {
		panic("idx parity impossible")
	}

	swapCnt := len(abIdx)/2 + len(baIdx)/2
	if len(abIdx)%2 == 1 && len(baIdx)%2 == 1 {
		swapCnt += 2
	}
	fmt.Println(swapCnt)

	for i := 0; i < len(abIdx)/2; i++ {
		fmt.Println(abIdx[2*i], abIdx[2*i+1])
	}
	for i := 0; i < len(baIdx)/2; i++ {
		fmt.Println(baIdx[2*i], baIdx[2*i+1])
	}

	if len(abIdx)%2 == 1 && len(baIdx)%2 == 1 {
		abLast := abIdx[len(abIdx)-1]
		baLast := baIdx[len(baIdx)-1]
		fmt.Println(abLast, abLast)
		fmt.Println(abLast, baLast)
	}
}
