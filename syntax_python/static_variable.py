def main():
    lpf.g = 0
    '''
    함수 static 변수 초기화, c언어에서 static 변수는 작동은 글로벌 변수와 동일하지만, 함수안에서만 해당 변수를 호출할 수 있게끔 블록화되어 있어 많이 사용하였는데,
    python 에서는 부르기를 static 변수라고 부르는 것이지, 사실상 해당 함수 밖에서도 호출이 가능하므로.., 블록화(block)가 안된다.
    '''
    
    lpf(3)
    lpf(3)
    lpf(3)


def lpf(u: (int))->int:
    lpf.g +=u               # 함수 안에 static 변수 선언, 단 초기화는 밖에서 해주어야 한다.
    print(lpf.g)
    return lpf.g

if __name__=="__main__":
    main()
    print(lpf.g+999)