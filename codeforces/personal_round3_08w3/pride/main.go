package main

import "fmt"

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}

	oneCnt := 0
	for _, ai := range a {
		if ai == 1 {
			oneCnt++
		}
	}
	if oneCnt > 0 {
		fmt.Println(n - oneCnt)
		return
	}

	minInterval := n
	for l := 0; l < n; l++ {
		cur := a[l]
		for r := l + 1; r < n; r++ {
			cur = gcd(cur, a[r])
			if cur == 1 {
				if (r - l) < minInterval {
					minInterval = r - l
				}
				break
			}
		}
	}
	if minInterval == n {
		fmt.Println(-1)
		return
	}
	fmt.Println(minInterval + n - 1)
}
