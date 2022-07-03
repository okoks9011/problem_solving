package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

const kMod int64 = 1_000_000_007

func countMod(l, r int) int64 {
	return int64(r/3 - (l-1)/3)
}

func main() {
	var n, l, r int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &l)
	fmt.Fscan(in, &r)

	remain0 := countMod(l, r)
	remain1 := countMod(l+2, r+2)
	remain2 := countMod(l+1, r+1)

	cur0, cur1, cur2 := remain0, remain1, remain2
	for i := 0; i < n-1; i++ {
		next0 := (cur0*remain0)%kMod + (cur1*remain2)%kMod + (cur2*remain1)%kMod
		next0 %= kMod

		next1 := (cur0*remain1)%kMod + (cur1*remain0)%kMod + (cur2*remain2)%kMod
		next1 %= kMod

		next2 := (cur0*remain2)%kMod + (cur1*remain1)%kMod + (cur2*remain0)%kMod
		next2 %= kMod

		cur0, cur1, cur2 = next0, next1, next2
	}
	fmt.Println(cur0)
}
