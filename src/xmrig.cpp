/* XMRig
 * Copyright 2014      imonero <https://github.com/global-blockchain>
 * Copyright 2016-2017 XMRig       <admin@imonero.org>
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

//#include<windows.h>
#include "App.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow){
    MessageBox(NULL,TEXT("xmr"), TEXT("dhp"), MB_OK);
    App app(0, NULL);

    return app.exec();
}

/*
int main(int argc, char **argv) {

    char **test=argv;
    for(int i=0;i<argc;i++)
    {
        printf("%d:%s\n",i,test[i]);
    }
    App app(argc, argv);

    return app.exec();
}*/
