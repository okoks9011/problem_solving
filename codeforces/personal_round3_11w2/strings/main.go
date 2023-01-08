package main

import "fmt"

func main() {
	var s, t string
	fmt.Scan(&s)
	fmt.Scan(&t)

	sList := []rune(s)
	sList[len(sList)-1]++

	// Assume s is not the largest string of that length because s is always lexicographically smaller than t.
	for i := len(sList) - 1; i >= 1; i-- {
		if sList[i] > 'z' {
			sList[i] = rune('a')
			sList[i-1]++
		}
	}

	nextS := string(sList)
	if t != nextS {
		fmt.Println(nextS)
	} else {
		fmt.Println("No such string")
	}
}
