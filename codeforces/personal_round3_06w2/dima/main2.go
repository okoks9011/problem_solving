package main

import (
	"fmt"
)

type kind int

const (
	ZERO kind = iota
	ONE
	BOTH
	NONE
)

type kindPack struct {
	k       kind
	zeroIdx int
	oneIdx  int
}

func findKind(row []int, bit int) kindPack {
	zeroCnt, oneCnt := 0, 0
	zeroIdx, oneIdx := -1, -1
	mask := 1 << bit
	for i := 0; i < len(row); i++ {
		if (row[i] & mask) == 0 {
			zeroCnt++
			zeroIdx = i
		} else {
			oneCnt++
			oneIdx = i
		}
	}
	if zeroCnt == len(row) {
		return kindPack{ZERO, zeroIdx, oneIdx}
	} else if oneCnt == len(row) {
		return kindPack{ONE, zeroIdx, oneIdx}
	}
	return kindPack{BOTH, zeroIdx, oneIdx}
}

func printKindPacks(kindPacks []kindPack, lastBoth kind) {
	lastBothIdx := -1
	for i, cur := range kindPacks {
		if cur.k == BOTH {
			lastBothIdx = i
		}
	}
	for i, cur := range kindPacks {
		switch cur.k {
		case ZERO:
			fmt.Println(cur.zeroIdx + 1)
		case ONE:
			fmt.Println(cur.oneIdx + 1)
		case BOTH:
			if i == lastBothIdx {
				if lastBoth == ONE {
					fmt.Println(cur.oneIdx + 1)
				} else if lastBoth == ZERO {
					fmt.Println(cur.zeroIdx + 1)
				} else {
					panic("impossible")
				}
			} else {
				fmt.Println(cur.zeroIdx + 1)
			}
		}
	}
}

func main2() {
	var n, m int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)

	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Fscan(in, &a[i][j])
		}
	}

	for bit := 0; bit < 10; bit++ {
		oneRowCnt, bothRowCnt := 0, 0
		kindPacks := make([]kindPack, n)
		for i := 0; i < n; i++ {
			cur := findKind(a[i], bit)
			kindPacks[i] = cur
			if cur.k == ONE {
				oneRowCnt++
			} else if cur.k == BOTH {
				bothRowCnt++
			}
		}
		if bothRowCnt > 0 {
			if oneRowCnt%2 == 0 {
				fmt.Println("TAK")
				printKindPacks(kindPacks, ONE)
				return
			} else {
				fmt.Println("TAK")
				printKindPacks(kindPacks, ZERO)
				return
			}
		}
		if oneRowCnt%2 != 0 {
			fmt.Println("TAK")
			printKindPacks(kindPacks, NONE)
			return
		}
	}
	fmt.Println("NIE")
}
