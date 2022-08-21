package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"sort"
)

var in = bufio.NewReader(os.Stdin)

func main() {
	var n, m int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)

	a := make([]int, n)
	aCnt := make(map[int]int)
	for i := range a {
		fmt.Fscan(in, &a[i])
		aCnt[a[i]]++
	}

	b := make([]int, n)
	bCnt := make(map[int]int)
	for i := range b {
		fmt.Fscan(in, &b[i])
		bCnt[b[i]]++
	}

	if len(aCnt) != len(bCnt) {
		log.Fatal("impossible")
	}

	var aKeys []int
	for aKey := range aCnt {
		aKeys = append(aKeys, aKey)
	}
	sort.Ints(aKeys)

	var bKeys []int
	for bKey := range bCnt {
		bKeys = append(bKeys, bKey)
	}
	sort.Ints(bKeys)

	result := m
	for shift := 0; shift < len(aCnt); shift++ {
		baseDiff := (m + bKeys[shift] - aKeys[0]) % m

		isValid := true
		for i := 0; i < len(aCnt); i++ {
			bi := bKeys[(shift+i)%len(aCnt)]
			ai := aKeys[i]
			curDiff := (m + bi - ai) % m
			if curDiff != baseDiff || bCnt[bi] != aCnt[ai] {
				isValid = false
				// Escape from the inner loop.
				break
			}
		}
		if isValid {
			if baseDiff < result {
				result = baseDiff
			}
		}
	}
	fmt.Println(result)
}
