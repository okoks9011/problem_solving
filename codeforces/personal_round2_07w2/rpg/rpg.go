package main

import "fmt"

func min(x, y int) int {
	if x > y {
		return y
	} else {
		return x
	}
}

func max(x, y int) int {
	if x < y {
		return y
	} else {
		return x
	}
}

func FillRemain(remainP, remainF, w, cntW int) int {
	pickP := min((remainP / w), cntW)
	pickF := min((remainF / w), cntW-pickP)
	return pickP + pickF
}

func Solve() {
	var p, f int
	var cntS, cntW, s, w int
	fmt.Scan(&p)
	fmt.Scan(&f)
	fmt.Scan(&cntS)
	fmt.Scan(&cntW)
	fmt.Scan(&s)
	fmt.Scan(&w)

	if p < f {
		p, f = f, p
	}
	if w < s {
		cntS, cntW = cntW, cntS
		s, w = w, s
	}

	selected := 0

	pick := min((p / s), cntS)
	curP := p - pick*s
	cntS -= pick
	selected += pick
	iterP := pick

	pick = min((f / s), cntS)
	curF := f - pick*s
	cntS -= pick
	selected += pick

	maxRemain := 0
	for i := iterP; i >= 0; i-- {
		maxRemain = max(maxRemain, FillRemain(curP, curF, w, cntW))
		curP += s
		curF -= s
		if curF < 0 {
			break
		}
	}
	fmt.Println(selected + maxRemain)
}

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		Solve()
	}
}
