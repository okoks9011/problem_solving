package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	if n%2 == 0 {
		fmt.Println("white")
		fmt.Println("1 2")
	} else {
		fmt.Println("black")
	}
}
