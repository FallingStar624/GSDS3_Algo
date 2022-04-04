
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    for (int i=0; i<N+1; i++) {
        for (int j=0; j<i; j++) {
            cout << " ";
        }
        for (int k=0; k<N-i;k++){
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
