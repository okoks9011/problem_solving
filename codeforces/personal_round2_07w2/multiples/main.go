package main

import "fmt"

func solveOne(a []int64) {
	fmt.Println("1 1")
	fmt.Println("0")
	fmt.Println("1 1")
	fmt.Println("0")
	fmt.Println("1 1")
	fmt.Printf("%d\n", -a[0])
}

func main() {
	var n int64
	fmt.Scan(&n)

	a := make([]int64, 0, n)
	for i := int64(0); i < n; i++ {
		var ai int64
		fmt.Scan(&ai)
		a = append(a, ai)
	}

	if n == 1 {
		solveOne(a)
		return
	}

	fmt.Println("1 1")
	fmt.Printf("%d\n", -a[0])
	a[0] = 0

	fmt.Printf("1 %d\n", n)
	for _, ai := range a {
		fmt.Printf("%d ", ai*-n)
	}
	fmt.Println()

	fmt.Printf("2 %d\n", n)
	for i, ai := range a {
		if i == 0 {
			continue
		}
		fmt.Printf("%d ", ai*(n-1))
	}
	fmt.Println()
}
