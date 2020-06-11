void sortColors(vector<int>& v) {
    int one = 0, zero = 0, two = v.size() - 1;
    while (one<two)
    {
        if (v[one] == 2)
        {
            swap(v[one], v[two]);
            two--;
        }
        else if (v[one] == 1)
        {
            swap(v[one], v[zero]);
            one++;
            zero++;
        }
        else
            one++;
    }
}
