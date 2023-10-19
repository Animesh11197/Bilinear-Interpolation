#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include<cmath>
#pragma warning(disable : 4996)
using namespace std;
using namespace std;
#define min(a,b) ((a) < (b) ? a : b)

void interpolate (float* original_img,float* output,float* test)
{
    printf("\nTHIS FUNCTION WILL PERFORM BILINEAR INTERPOLATION.!\n");
    //input dimension is 24*2
    //ouput dimension is 72*14
    float old_h = 24;
    float old_w = 2;
    float new_h = 72;
    float new_w = 14;
    float h_scale_factor = old_h / new_h;//old_h/new_h
    float w_scale_factor = old_w / new_w; //old_w / new_w
    for(int channel=0;channel < 8;channel++)
    { 

        for (int i = 0; i < new_h - 1; i++)
        {
            for (int j = 0; j < new_w - 3; j++)
            {
                //printf("\n*********************************************\n");
                //cout<<"i="<< i<< "\tj="<< j<<endl;
                //map the coordinates back to the original image
                float x = i * h_scale_factor;
                float y = j * w_scale_factor;
                //cout<<"x="<<x <<"\ty="<< y<<endl;
                //calculate the cordinates of 4 surrounding pixels
                int x_floor = floor(x);
                int x_ceil = min(old_h - 1, ceil(x));
                int y_floor = floor(y);
                int y_ceil = min(old_w - 1, ceil(y));
                float q;
                //cout<<"x_floor= "<<x_floor<<"\tx_ceil="<<x_ceil<<"\ty_floor="<<y_floor<<"\ty_ceil="<<y_ceil ;

                if ((x_ceil == x_floor) && (y_ceil == y_floor))
                {
                    q = original_img[(channel* 24 * 2 )+int(x) * 2 + int(y)];
                    //printf("\nq =%f\n", q);
                }
                else if (x_ceil == x_floor)
                {
                    float q1 = original_img[(channel * 24 * 2 ) + int(x) * 2 + int(y_floor)];
                    float q2 = original_img[(channel * 24 * 2 ) + int(x) * 2 + int(y_ceil)];
                    q = q1 * (y_ceil - y) + q2 * (y - y_floor);
                    //cout<<"\nq1="<<q1<<"\tq2="<<q2<<"\tq="<<q;
                }
                else if (y_ceil == y_floor)
                {
                    float q1 = original_img[(channel * 24 * 2 ) + int(x_floor) * 2 + int(y)];
                    float q2 = original_img[(channel * 24 * 2 ) + int(x_ceil) * 2 + int(y)];
                    q = (q1 * (x_ceil - x)) + (q2 * (x - x_floor));
                    //cout<<"\nq1="<<q1<<"\tq2="<<q2<<"\tq="<< q;
                }
                else
                {
                    float v1 = original_img[(channel * 24 * 2 ) + x_floor * 2 + y_floor];
                    float v2 = original_img[(channel * 24 * 2 ) + x_ceil * 2 + y_floor];
                    float v3 = original_img[(channel * 24 * 2 ) + x_floor * 2 + y_ceil];
                    float v4 = original_img[(channel * 24 * 2 ) + x_ceil * 2 + y_ceil];
                    //cout<<"\nv1="<<v1<<"\tv2="<<v2<<"\tv3="<<v3<<"\tv4="<<v4;

                    float q1 = v1 * (x_ceil - x) + v2 * (x - x_floor);
                    float q2 = v3 * (x_ceil - x) + v4 * (x - x_floor);
                    q = q1 * (y_ceil - y) + q2 * (y - y_floor);
                    //cout<<"\nq1="<<q1<<"\tq2="<<q2<<"\tq="<<q;

                }

                output[(channel * 72 * 14) + ((i + 1) * 14) + j + 3] = q;

            }
        }


        for (int i = new_h - 1; i > 0; i--)
        {
            for (int j = 3; j > 0; j--)
            {
                output[(channel * 72 * 14) + (i * 14) + j - 1] = output[(channel * 72 * 14) + (i * 14 + j)];
                //output[(i * 14) + j - 1] = 0;

            }
        }

        for (int j = new_w - 1; j > -1; j--)
        {
            output[(channel * 72 * 14) + (0 * 14) + j] = output[(channel * 72 * 14) + (1 * 14 + j)];
            //output[(0 * 14) + j ] = 0;
        }

    }
    
    
    test[0] = 10;
    //return output;
}



void interpolate_72_2_72_14(float* original_img, float* output, float* test)
{
    printf("\nTHIS FUNCTION WILL PERFORM BILINEAR INTERPOLATION.!\n");
    //input dimension is 24*2
    //ouput dimension is 72*14
    float old_h = 72;
    float old_w = 2;
    float new_h = 72;
    float new_w = 14;
    float h_scale_factor = old_h / new_h;//old_h/new_h
    float w_scale_factor = old_w / new_w; //old_w / new_w
    for (int channel = 0; channel < 0; channel++)
    {

        for (int i = 0; i < new_h - 1; i++)
        {
            for (int j = 0; j < new_w - 3; j++)
            {
                //printf("\n*********************************************\n");
                //cout<<"i="<< i<< "\tj="<< j<<endl;
                //map the coordinates back to the original image
                float x = i * h_scale_factor;
                float y = j * w_scale_factor;
                //cout<<"x="<<x <<"\ty="<< y<<endl;
                //calculate the cordinates of 4 surrounding pixels
                int x_floor = floor(x);
                int x_ceil = min(old_h - 1, ceil(x));
                int y_floor = floor(y);
                int y_ceil = min(old_w - 1, ceil(y));
                float q;
                //cout<<"x_floor= "<<x_floor<<"\tx_ceil="<<x_ceil<<"\ty_floor="<<y_floor<<"\ty_ceil="<<y_ceil ;

                if ((x_ceil == x_floor) && (y_ceil == y_floor))
                {
                    q = original_img[(channel * 24 * 2) + int(x) * 2 + int(y)];
                    //printf("\nq =%f\n", q);
                }
                else if (x_ceil == x_floor)
                {
                    float q1 = original_img[(channel * 24 * 2) + int(x) * 2 + int(y_floor)];
                    float q2 = original_img[(channel * 24 * 2) + int(x) * 2 + int(y_ceil)];
                    q = q1 * (y_ceil - y) + q2 * (y - y_floor);
                    //cout<<"\nq1="<<q1<<"\tq2="<<q2<<"\tq="<<q;
                }
                else if (y_ceil == y_floor)
                {
                    float q1 = original_img[(channel * 24 * 2) + int(x_floor) * 2 + int(y)];
                    float q2 = original_img[(channel * 24 * 2) + int(x_ceil) * 2 + int(y)];
                    q = (q1 * (x_ceil - x)) + (q2 * (x - x_floor));
                    //cout<<"\nq1="<<q1<<"\tq2="<<q2<<"\tq="<< q;
                }
                else
                {
                    float v1 = original_img[(channel * 24 * 2) + x_floor * 2 + y_floor];
                    float v2 = original_img[(channel * 24 * 2) + x_ceil * 2 + y_floor];
                    float v3 = original_img[(channel * 24 * 2) + x_floor * 2 + y_ceil];
                    float v4 = original_img[(channel * 24 * 2) + x_ceil * 2 + y_ceil];
                    //cout<<"\nv1="<<v1<<"\tv2="<<v2<<"\tv3="<<v3<<"\tv4="<<v4;

                    float q1 = v1 * (x_ceil - x) + v2 * (x - x_floor);
                    float q2 = v3 * (x_ceil - x) + v4 * (x - x_floor);
                    q = q1 * (y_ceil - y) + q2 * (y - y_floor);
                    //cout<<"\nq1="<<q1<<"\tq2="<<q2<<"\tq="<<q;

                }

                output[(channel * 72 * 14) + ((i + 1) * 14) + j + 3] = q;

            }
        }


        for (int i = new_h - 1; i > 0; i--)
        {
            for (int j = 3; j > 0; j--)
            {
                output[(channel * 72 * 14) + (i * 14) + j - 1] = output[(channel * 72 * 14) + (i * 14 + j)];
                //output[(i * 14) + j - 1] = 0;

            }
        }

        for (int j = new_w - 1; j > -1; j--)
        {
            output[(channel * 72 * 14) + (0 * 14) + j] = output[(channel * 72 * 14) + (1 * 14 + j)];
            //output[(0 * 14) + j ] = 0;
        }

    }


    //test[0] = 10;
    //return output;
}




int main() {

    cout << "initializing Interpolation:\n" << endl;

    //declare bilinear input
    float input[24][2];
    float output[72][14];
    float test[] = {5};
    int N = 2;
    float in[24 * 2 * 8];
    float out[72 * 14 * 8];

    FILE* fin2;
    FILE* fin2_out;
    float inputsample2;
    //fin2 = fopen("Bilinear_input.dat", "r");
    fin2 = fopen("input_interpolate_8channel.dat", "r");
    if (!fin2) {
        printf("could not open file \a\n");
        exit(101);
    }

    //insert input into initialised variable
    for (int channel = 0; channel < 8; channel++)
    {
        for (int i = 0; i < 24; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                fscanf(fin2, "%f", &inputsample2);
                in[(channel * 24 * 2) + (i * N + j)] = inputsample2;
                //input[i][j] = inputsample2;
                printf("%f\t", in[(channel * 24 * 2) + (i * N + j)]);
            }
            printf("\n");
        }
        cout << "-----" << channel << "----\n";
    }
    //for (int i = 0; i < 72; i++)
    //{
    //    for (int j = 0; j < 14; j++)
    //    {
    //        //fscanf(fin2, "%f", &inputsample2);
    //        out[i * 14 + j] = -;
    //        //input[i][j] = inputsample2;
    //        printf("%f,", out[i * 14 + j]);

    //    }
    //    printf("\n\n");
    //}


    //call interpolation function
    interpolate(in, out,test);
        /*float test_var = 2.86;
        cout << "floor of " << test_var << "is "<< floor(test_var)<<endl;
        cout << "Ceil of " << test_var << "is "<<ceil(test_var);
        printf("print number:\t %f\n", test_var);*/


    //CREATE THE OUTPUT FILE:
    //fin2_out = fopen("Bilinear_generated.dat", "w");//1 channel
    fin2_out = fopen("output_interpolate_8channel.dat", "w");//8 channel
    if (!fin2_out) {
        printf("could not open file \a\n");
        exit(101);
    }

    //int channel=2;
    for (int channel = 0; channel < 8; channel++)
    {
        for (int i = 0; i < 72; i++)
        {
            for (int j = 0; j < 14; j++)
            {
                //fscanf(fin2, "%f", &inputsample2);
                //in[i * N + j] = inputsample2;
                //input[i][j] = inputsample2;
                //printf("%f ", out[i*14+j]);
                cout << (channel * 72 * 14) + (i * 14) + j + 1 << ")" << out[(channel * 72 * 14) + (i * 14 + j)] << "\t";
                fprintf(fin2_out, "%f\n", out[(channel * 72 * 14) + (i * 14 + j)]);
            }
            printf("\n\n");
        }
        cout << "-----"<<channel<<"----\n";
    }
    //cout << "\n\ntest value := " << test[0];

	return 0;
}