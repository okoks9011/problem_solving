package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader
var out *bufio.Reader

func solve() {
	var n int
	fmt.Fscan(in, &n)
	var k int64
	fmt.Fscan(in, &k)

	var s string
	fmt.Fscan(in, &s)
	t := []rune(s)

	var pos []int
	for i, ti := range t {
		if ti == '0' {
			pos = append(pos, i)
		}
	}
	next := n
	for i, ti := range t {
		if ti == '1' {
			next = i
			break
		}
	}

	for pi := 0; pi < len(pos) && k > 0; pi++ {
		curZero := pos[pi]
		if curZero < next {
			continue
		}
		if int64(curZero-next) <= k {
			k -= int64(curZero - next)
		} else {
			remain := curZero - int(k)
			t[remain], t[curZero] = t[curZero], t[remain]
			break
		}
		t[next], t[curZero] = t[curZero], t[next]
		next++
	}
	fmt.Println(string(t))
}

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var q int
	fmt.Fscan(in, &q)

	for i := 0; i < q; i++ {
		solve()
	}
}
