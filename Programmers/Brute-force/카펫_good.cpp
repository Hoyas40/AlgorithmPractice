//better solution

vector<int> solution2(int brown, int red) 
{
    // wh = b + r
    // (w-2)(b-2)=r
    // 위 두 방정식을 정리하면, w = b/2 + 2 - h 가 나온다.
    int len = brown / 2 + 2;

    int w = len - 3;
    int h = 3;

    while(w >= h)
    {
        if(w * h == (brown + red)) 
            break;

        w--;
        h++;
    }

    return vector<int>{w, h};
}