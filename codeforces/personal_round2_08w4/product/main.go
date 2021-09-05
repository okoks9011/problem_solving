package main

import "fmt"

func gcd(a, b int) int {
	if b > a {
		return gcd(b, a)
	}
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	var n int
	fmt.Scan(&n)

	candi := []int64{}
	candiProd := int64(1)
	for i := 1; i < n; i++ {
		if gcd(i, n) != 1 {
			continue
		}
		candi = append(candi, int64(i))
		candiProd *= int64(i)
		candiProd %= int64(n)
	}
	if candiProd != 1 {
		for i, v := range candi {
			if v != candiProd {
				continue
			}
			candi = append(candi[:i], candi[i+1:]...)
			break
		}
	}
	fmt.Println(len(candi))
	for _, v := range candi {
		fmt.Print(v, " ")
	}
	fmt.Println()
}
