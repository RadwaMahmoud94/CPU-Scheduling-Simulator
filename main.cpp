#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    int ch;
    cout << "for HRRN press:1 and for STRF press:2" << endl;
    cin >> ch;
    if (ch == 1) {
        int n;
        cout << "please,enter the number of processes\n";
        cin >> n;
        int p[n], a[n], b[n], r[n];
        cout << "please,enter processes ID\n";
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        cout << "please,enter arrival time of each process\n";
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << "please,enter the burst time of each process\n";
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int q = 0;
        r[0] = p[0];
        int finish = b[0];
        int s[n], d[n], f[n], turnaround[n], waitingtime[n];
        turnaround[0] = b[0] - a[0];
        waitingtime[0] = turnaround[0] - b[0];
        cout << "response ratio for p0 = " << (float) ((finish - a[0]) + b[0]) / b[0] << "\n";
        int g = 1, h = 1;
        for (int u = 1; u < n;) {
            int c = 0;
            int l = u;
            for (int i = 0, x = l; x < n; i++, x++) {
                if (finish >= a[x]) {
                    s[i] = p[x];
                    d[i] = a[x];
                    f[i] = b[x];
                    c++;
                }
            }
            if (c == 1) {
                float z = ((finish - d[0]) + f[0]) / f[0];
                cout << "response ratio for p " << c << "= " << z << "\n";
                r[g] = s[0];
                finish = finish + f[0];
                turnaround[h] = finish - d[0];
                waitingtime[h] = turnaround[h] - f[0];
                //cout<<finish<<"\n";
                g++;
                u++;
                h++;
            } else {
                int e = 0, y = 0;

                while (e < c) {
                    int o = 0;
                    float w[n];

                    for (int t = 0; t < n; t++) {
                        w[n] = 0;
                    }


                    for (int t = 0; t < c; t++) {
                        if (d[t] != -1) {
                            w[t] = (float) ((finish - d[t]) + f[t]) / f[t];
                        } else
                            w[t] = 0;
                    }
                    /* for(int j=0;j<c;j++)
                     {
                         cout<<w[j]<<"this\n";
                     }*/
                    float maxi = w[0];
                    for (int t = 1; t < c; t++) {
                        if (maxi < w[t]) {
                            maxi = w[t];
                            y = t;
                        } else if (maxi == w[0]) {
                            y = 0;
                        }
                    }
                    //cout<<"y is "<<y<<endl;
                    r[g] = s[y];
                    g++;
                    finish = finish + f[y];
                    turnaround[h] = finish - d[y];
                    waitingtime[h] = turnaround[h] - f[y];
                    cout << "response ratio for p " << y + 2 << "= " << maxi << "\n";
                    s[y] = f[y] = d[y] = -1;
                    //cout<<finish<<"\n";
                    e++;
                    u++;
                    h++;
                }
            }
        }
        cout << "The order of how the processes were scheduled is:p" << r[0];

        for (int i = 1; i < n; i++) {
            cout << "-> p" << r[i];
        }
        cout << "\n";
        int sum = 0;
        float average;
        for (int i = 0; i < n; i++) {
            sum += turnaround[i];
        }

        average = (float) sum / n;
        cout << "Average turnaround time=" << average << "\n";
        int summition = 0;
        for (int i = 0; i < n; i++) {
            summition += waitingtime[i];
        }
        float avsum;
        avsum = (float) summition / n;
        cout << "Average waiting time=" << avsum << "\n";
    } else {
        int Arrival[100], Brust[100], Cop[100], ID[100], Proc[1000];
        int waiting[10], turnaround[10], finish, num;
        float avg = 0, tt = 0;

        cout << "Enter the number of Processes " << endl;
        cin >> num;
        for (int i = 0; i < num; i++) {
            cout << "Enter arrival time , Brust time and ID of process: " << endl;
            cin >> Arrival[i] >> Brust[i] >> ID[i];
        }


        for (int i = 0; i < num; i++)
            Cop[i] = Brust[i];

        Brust[99] = INT_MAX;
        int counter = 0;
        int time, small = 0, small2 = 0, ccount = 0;
        for (time = 0; counter != num; time++) {
            small = 99;
            for (int i = 0; i < num; i++) {
                if (Arrival[i] <= time && Brust[i] <= small && Brust[i] > 0) {

                    if (Arrival[i] > Arrival[small2] && Brust[i] == Brust[small2]) {
                        small = Brust[small2];
                        continue;
                    }


                    small2 = i;
                    small = Brust[i];


                    /* Proc[ccount] = ID[small];
                       ccount++;*/
                }

            }
            Proc[ccount] = ID[small2];
            ccount++;
            Brust[small2]--;


            if (Brust[small2] == 0) {
                counter++;
                finish = time + 1;
                turnaround[small2] = finish - Arrival[small2];
                waiting[small2] = turnaround[small2] - Cop[small2];

            }
        }
        cout << "Processes.ID"
             << "Arrival time "
             << "Brust time " << endl;

        for (int i = 0; i < num; i++) {
            cout << ID[i] << "\t" << "\t" << Arrival[i] << "\t" << "\t" << Cop[i] << "\t" << endl;
            avg = avg + waiting[i];
            tt = tt + turnaround[i];
        }
        for (int i = 0; i < ccount; i++) {
            if (Proc[i] == Proc[i + 1]) {
                continue;
            }
            cout << "p" << Proc[i] << " =>";
        }
        cout << endl;

        cout << "Average waiting time =" << avg / num << endl;
        cout << "Average Turnaround time =" << tt / num << endl;
    }

    return 0;
}
