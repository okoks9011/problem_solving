package main

import "fmt"

func solve() {
	var r, c int
	fmt.Scan(&r)
	fmt.Scan(&c)

	width := 2*c + 1
	rowPlus := make([]byte, width)
	for i := 0; i < width; i++ {
		if i%2 == 0 {
			rowPlus[i] = '+'
		} else {
			rowPlus[i] = '-'
		}
	}

	rowDot := make([]byte, width)
	for i := 0; i < width; i++ {
		if i%2 == 0 {
			rowDot[i] = '|'
		} else {
			rowDot[i] = '.'
		}
	}

	rowPlus[0] = '.'
	rowPlus[1] = '.'
	rowDot[0] = '.'
	rowDot[1] = '.'
	fmt.Println(string(rowPlus))
	fmt.Println(string(rowDot))

	rowPlus[0] = '+'
	rowPlus[1] = '-'
	rowDot[0] = '|'
	rowPlusStr := string(rowPlus)
	rowDotStr := string(rowDot)
	fmt.Println(rowPlusStr)

	for i := 1; i < r; i++ {
		fmt.Println(rowDotStr)
		fmt.Println(rowPlusStr)
	}
}

func main() {
	var t int
	fmt.Scan(&t)

	for i := 0; i < t; i++ {
		fmt.Printf("Case #%d:\n", i+1)
		solve()
	}
}
