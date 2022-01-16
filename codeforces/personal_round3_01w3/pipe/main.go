package main

import (
	"bufio"
	"fmt"
	"os"
)

type Direction int

const (
	VERTICAL Direction = iota
	HORIZONTAL
)

var in *bufio.Reader

func solve() {
	var n int
	fmt.Fscan(in, &n)

	grid := make([]string, 2)
	fmt.Fscan(in, &grid[0])
	fmt.Fscan(in, &grid[1])

	directionType := map[byte]int{
		'1': 1,
		'2': 1,
		'3': 2,
		'4': 2,
		'5': 2,
		'6': 2,
	}

	row, col := 0, 0
	d := HORIZONTAL
	for col < n {
		t := directionType[grid[row][col]]
		switch d {
		case HORIZONTAL:
			if t == 1 {
				col++
			} else if t == 2 {
				row ^= 1
				d = VERTICAL
			} else {
				panic("impossible")
			}
		case VERTICAL:
			if t == 1 {
				fmt.Println("NO")
				return
			} else if t == 2 {
				col++
				d = HORIZONTAL
			} else {
				panic("impossible")
			}
		default:
			panic("impossible")
		}
	}
	if row == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var q int
	fmt.Fscan(in, &q)

	for i := 0; i < q; i++ {
		solve()
	}
}
