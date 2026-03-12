template <typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (T& x : v)
        in >> x;
    return in;
}
template <typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    for (const T& x : v)
        out << x << " ";
    return out;
}
