#include <Windows.h>
#include <iostream>
#include "C:/Users/Matheus/Documents/Libs/Projeto 0/glut-3.7.6-bin/glut.h"

#include "Sphere.h"
#include "Cube.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Scenary.h"

#pragma comment(lib, "C:/Users/Matheus/Documents/Libs/Projeto 0/glut-3.7.6-bin/glut32.lib")

using namespace std;

float x_start_position = 100;
float y_start_position = 100;

float H = 500;
float W = 500;

#define PI 3.1415

HWND hWnd;

float* test;

void renderScene(void) {
    glDrawPixels(H, W, GL_RGB, GL_FLOAT, test);
    glutSwapBuffers();
    glutPostRedisplay();
}

void Raycaster() {
    /* ================================== Materiais ========================================== */
    // Pessego -----------------------------------------------
    Point La1 = { 0.831, 0.454, 0.337 };       //ambiente
    Point Ld1 = { 0.831, 0.454, 0.337 };       //difuso
    Point Ls1 = { 0.931, 0.554, 0.337 };       //
    double met1 = 0;
    auto* material1 = new Material(La1, Ld1, Ls1, met1);
    
    // Vermelho vinho ----------------------------------------
    Point La2 = { 0.894, 0.8, 0.705 };
    Point Ld2 = { 0.894, 0.8, 0.705 };
    Point Ls2 = { 0.894, 0.8, 0.705 };
    double met2 = 100;
    auto* material2 = new Material(La2, Ld2, Ls2, met2);

    // Preto magenta -----------------------------------------
    Point La3 = { 0.078, 0.078, 0.078 };
    Point Ld3 = { 0.078, 0.078, 0.078 };
    Point Ls3 = { 0.078, 0.078, 0.078 };
    double met3 = 100;
    auto* material3 = new Material(La3, Ld3, Ls3, met3);

    // Fosco -------------------------------------------------
    Point La4 = { 0.282, 0.282, 0.254 };
    Point Ld4 = { 0.282, 0.282, 0.254 };
    Point Ls4 = { 0.282, 0.282, 0.254 };
    double met4 = 12;
    auto* material4 = new Material(La4, Ld4, Ls4, met4);

    // Azul marinho -------------------------------------------
    Point La5 = { 0.141, 0.141, 0.549 };
    Point Ld5 = { 0.141, 0.141, 0.549 };
    //Point Ls5 = { 0, 0, 0 };
    Point Ls5 = { 0.141, 0.141, 0.549 };
    double met5 = 51;
    auto* material5 = new Material(La5, Ld5, Ls5, met5);

    // Azul meio claro ---------------------------------------
    Point ka6 = { 0.015, 0.486, 0.674 };
    Point kd6 = { 0.015, 0.486, 0.674 };
    Point ks6 = { 0.015, 0.486, 0.674 };
    double m6 = 76;
    auto* material6 = new Material(ka6, kd6, ks6, m6);

    // Imbuia ------------------------------------------------
    Point La7 = { 0.501, 0.329, 0.172 };
    Point Ld7 = { 0.501, 0.329, 0.172 };
    Point Ls7 = { 0.501, 0.329, 0.172 };
    double met7 = 76;
    auto* material7 = new Material(La7, Ld7, Ls7, met7);

    // Imbuia mais claro -------------------------------------
    Point La8 = { 0.601, 0.429, 0.272 };
    Point Ld8 = { 0.601, 0.429, 0.272 };
    Point Ls8 = { 0.601, 0.429, 0.272 };
    double met8 = 76;
    auto* material8 = new Material(La8, Ld8, Ls8, met8);

    // Laranja -----------------------------------------------
    Point La9 = { 0.768, 0.286, 0.031 };
    Point Ld9 = { 0.968, 0.286, 0.031 };
    Point Ls9 = { 0.768, 0.286, 0.031 };
    double met9 = 50;
    auto* material9 = new Material(La9, Ld9, Ls9, met9);

    // Meio amarelo ------------------------------------------
    Point La10 = { 0.839, 0.764, 0.262 };
    Point Ld10 = { 0.839, 0.764, 0.262 };
    Point Ls10 = { 0.839, 0.764, 0.262 };
    double met10 = 50;
    auto* material10 = new Material(La10, Ld10, Ls10, met10);

    // Barro -------------------------------------------------
    Point La11 = { 0.294, 0.078, 0.047 };
    Point Ld11 = { 0.294, 0.078, 0.047 };
    Point Ls11 = { 0.294, 0.078, 0.047 };
    double met11 = 50;
    auto* material11 = new Material(La11, Ld11, Ls11, met11);

    // Madeira -----------------------------------------------
    Point La12 = { 0.262, 0.203, 0.192 };
    Point Ld12 = { 0.294, 0.078, 0.047 };
    Point Ls12 = { 0.294, 0.078, 0.047 };
    double met12 = 50;
    auto* material12 = new Material(La12, Ld12, Ls12, met12);

    // Verde -------------------------------------------------
    Point La13 = { 0.380, 0.466, 0.086 };
    Point Ld13 = { 0.294, 0.078, 0.047 };
    Point Ls13 = { 0.380, 0.466, 0.086 };
    double met13 = 50;
    auto* material13 = new Material(La13, Ld13, Ls13, met13);

    // Dourado -----------------------------------------------
    Point La14 = { 0.894, 0.737, 0.360 };
    Point Ld14 = { 0.894, 0.737, 0.360 };
    Point Ls14 = { 0.894, 0.737, 0.360 };
    double met14 = 1000;
    auto* material14 = new Material(La14, Ld14, Ls14, met14);

    // Azul da pintura ---------------------------------------
    Point La15 = { 0.392, 0.552, 0.741 };
    Point Ld15 = { 0.392, 0.552, 0.741 };
    Point Ls15 = { 0.392, 0.552, 0.741 };
    double met15 = 50;
    auto* material15 = new Material(La15, Ld15, Ls15, met15);

    // Verde1 da pintura --------------------------------------
    Point La16 = { 0.152, 0.360, 0.192 };
    Point Ld16 = { 0.152, 0.360, 0.192 };
    Point Ls16 = { 0.152, 0.360, 0.192 };
    double met16 = 50;
    auto* material16 = new Material(La16, Ld16, Ls16, met16);

    // Verde2 da pintura --------------------------------------
    Point La17 = { 0.341, 0.564, 0.349 };
    Point Ld17 = { 0.341, 0.564, 0.349 };
    Point Ls17 = { 0.341, 0.564, 0.349 };
    double met17 = 50;
    auto* material17 = new Material(La17, Ld17, Ls17, met17);

    // Laranja sol --------------------------------------------
    //0.925, 0.733, 0.105
    Point La18 = { 0.925, 0.733, 0.105 };
    Point Ld18 = { 0.925, 0.733, 0.105 };
    Point Ls18 = { 0.925, 0.733, 0.105 };
    double met18 = 50;
    auto* material18 = new Material(La18, Ld18, Ls18, met18);

    // Branco rosado -------------------------------------------
    Point La19 = { 0.980, 0.925, 0.694 };
    Point Ld19 = { 0.980, 0.925, 0.694 };
    Point Ls19 = { 0.980, 0.925, 0.694 };
    double met19 = 50;
    auto* material19 = new Material(La19, Ld19, Ls19, met19);

    // Objetos do Cenario ===============================================================================
    // -------------------------------- Paredes e Chão --------------------------------------------------
    Cube Parede1(40, { -20, -6, -50 }, *material1);
    Cube Parede2(40, {  0, -6, -70 }, *material1);
    Cube Chao(40, { 0, -20, -50 }, *material2);
    Cube cubo(2, { 0, 0, 0 }, * material9);

    // scalling -> alterar o tamanho dos objetos
    // translating -> mover o objeto
    // rotate -> rotacionar o objeto

    Parede1.Scalling(Point(0.05, 0.7, 1.0));
    Parede2.Scalling(Point(1.0, 0.7, 0.05));
    Chao.Scalling(Point(1.0, 0.05, 1.0));
    
    // -------------------------------- Cama ------------------------------------------------------------
    Cylinder CamaPe1(0.5, 2, Point(-18, -19, -68), Point(0, 1, 0), *material3); //tras
    Cylinder CamaPe2(0.5, 2, Point(-18, -19, -45), Point(0, 1, 0), *material3); //frente
    Cylinder CamaPe3(0.5, 2, Point(-4, -19, -68), Point(0, 1, 0), *material3);  //tras
    Cylinder CamaPe4(0.5, 2, Point(-4, -19, -45), Point(0, 1, 0), *material3);  //frente 

    Cube CamaP1(14, { -11, -16, -56.5 }, *material4);
    Cube CamaP2(14, { -11, -14, -56.5 }, *material5);

    CamaP1.Scalling(Point(1.25, 0.15, 1.80));
    CamaP2.Scalling(Point(1.25, 0.15, 1.80));

    Cube Travesseiro(3, { -9.5, -13, -65 }, *material6);
    Travesseiro.Scalling(Point(2.5, 1, 2));

    // -------------------------------- Mesa ------------------------------------------------------------
    Cube MesaPe1(4, { 16, -15, -68 }, *material7); //1
    Cube MesaPe2(4, { 6, -15, -68 }, *material7);  //2
    Cube MesaPe3(4, { 16, -15, -60 }, *material7); //3
    Cube MesaPe4(4, { 6, -15, -60 }, *material7);  //4 

    MesaPe1.Scalling(Point(0.2, 2.0, 0.2));
    MesaPe2.Scalling(Point(0.2, 2.0, 0.2));
    MesaPe3.Scalling(Point(0.2, 2.0, 0.2));
    MesaPe4.Scalling(Point(0.2, 2.0, 0.2));

    Cube MesaCima(12, { 11, -11, -64 }, *material8);

    MesaCima.Scalling(Point(1.0, 0.2, 0.85));

    //------------------------------ Cadeira ------------------------------------------------------------
    Cube CadeiraPe1(2, { 9, -15, -58 }, * material7); 
    Cube CadeiraPe2(2, { 13, -15, -58 }, * material7); 
    Cube CadeiraPe3(2, { 9, -15, -54 }, * material7); 
    Cube CadeiraPe4(2, { 13, -15, -54 }, * material7); 

    Cube Cadeira(9, { 11, -13, -56 }, * material9);

    CadeiraPe1.Scalling(Point(0.2, 2.0, 0.2));
    CadeiraPe2.Scalling(Point(0.2, 2.0, 0.2));
    CadeiraPe3.Scalling(Point(0.2, 2.0, 0.2));
    CadeiraPe4.Scalling(Point(0.2, 2.0, 0.2));

    Cadeira.Scalling(Point(0.5, -0.1, 0.5));

    // -------------------------------- Abajur ----------------------------------------------------------
    Cone AbCorpo(1, 3, Point(14, -10, -65), Point(0, 1, 0), *material9);
    AbCorpo.scaling(Point(1.0, 2.0, 1.0));

    Cylinder AbCabeca(2, 3, Point(14, -6, -65), Point(0, 1, 0), *material10);
    AbCabeca.scaling(Point(1.0, 0.8, 1.0));

    // -------------------------------- Planta ----------------------------------------------------------
    Sphere PlantaC(2.5, { -16, -15, -35 } , *material13);

    Cone Jarro(2, 3, { -16, -18, -35 }, { 0, -1, 0}, *material11);
    Cylinder Tronco(0.5, 2, Point(-16, -18, -35), Point(0, 1, 0), *material12);

    // Quadro: ABAPURU ----------------------------------------------------------------------------------
    //-20, -6, -50 : PAREDE
    Cube Moldura1(2, { -19, -3, -40 }, *material14);
    Cube Moldura2(2, { 0, 0, 0 }, * material14);
    Cube Moldura3(2, { -19, -3, -51 }, * material14);
    Cube Moldura4(2, { 0, 0, 0 }, * material14);

    Moldura1.Scalling(Point(0.1, 5.0, 0.25));
    Moldura2.Scalling(Point(0.1, 5.2, 0.25));
    Moldura3.Scalling(Point(0.1, 5.0, 0.25));
    Moldura4.Scalling(Point(0.1, 5.2, 0.25));
    //-19, 1.68, -45.5
    Moldura2.Rotate(PI/2, { 1, 0, 0 });
    Moldura2.Translating(Point(-19, 1.68, -45.5));
    //-19, -7.68, -45.5
    Moldura4.Rotate(PI/2, { 1, 0, 0 });
    Moldura4.Translating(Point(-19, -7.68, -45.5));

    Cube Quadro(2, { -19, -3, -45.5 }, *material15);
    Quadro.Scalling(Point(0.1, 4.4, 5.2));

    Cube QChao(2, { -18.9998, -6.4, -45.5 }, *material16);
    QChao.Scalling(Point(0.1, 1, 5.2));

    Cube Cacto1(1, { -18.9998, -3.5, -48.5 }, *material17);
    Cube Cacto2(1, { -18.9998, -2, -49.5 }, *material17);
    Cube Cacto3(1, { -18.9998, -3.3, -49 }, *material17);
    Cacto1.Scalling(Point(0.2, 3.7, 0.8));
    Cacto2.Scalling(Point(0.2, 3.7, 0.8));
    Cacto3.Scalling(Point(0.2, 1.0, 0.8));

    Cube Abaporu(2, { -18.9998, -3.2, -42 }, *material19);
    Abaporu.Scalling(Point(0.2, 2.2, 1.4));
    
    Cube Sol(2, { -18.9998, -1, -45.5 }, *material10);
    Cube Sl1(1, { -18.998, -1, -45.5 }, *material18);
    Sol.Scalling(Point(0.1, 1.0, 1.0));
    Sl1.Scalling(Point(0.2, 0.8, 0.8));

    Cone cone2(2, 3, { 14, 2, 0 }, { 0, 1, 0 }, * material9);

    // ==================================================================================================
    //                     R    G    B
    AmbientLighting luzA(0.9, 0.9, 0.9);
    PointLighting luzP(0.6, 0.6, 0.6, { 0, 20, -50 });
    //0, -20, -50 : CHAO


    //Posição, p/ onde a cam. esta olhando, UP vector
    Camera cam1({ 40, 10, -50 }, { 0, -20, -50 }, { 40, 11, -50 }, -4, 5);
    Camera cam2({ -10, 0, 0 }, { 0, -20, -50 }, { -10, 1, 0 }, -4, 6);
    Camera cam3({ 35, 10, -20 }, { 0, -20, -50 }, { 35, 11, -20 }, -4, 5);
    Camera cam4({ 0, 50, -40 }, { 0, -20, -50 }, { 0, 51, -40 }, -4, 4);
    Camera camAux({ -11, 0, -56.5 }, { 14, -15, -65 }, { -11, 1, -56.5 }, -4, 4);
    Camera camPaint({ 60, 0, -50 }, { -19, -3, -45.5 }, { 60, 1, -50 }, -8, 2);

    Scenary* cenario = new Scenary();

    cenario->addLuzAmbiente(luzA);
    cenario->adicionarLuz(&luzP);

    cenario->adicionarObjeto(&Parede1);
    cenario->adicionarObjeto(&Parede2);
    cenario->adicionarObjeto(&Chao);
    cenario->adicionarObjeto(&cubo);

    cenario->adicionarObjeto(&CamaPe1);
    cenario->adicionarObjeto(&CamaPe2);
    cenario->adicionarObjeto(&CamaPe3);
    cenario->adicionarObjeto(&CamaPe4);
    cenario->adicionarObjeto(&CamaP1);
    cenario->adicionarObjeto(&CamaP2);
    cenario->adicionarObjeto(&Travesseiro);

    cenario->adicionarObjeto(&MesaPe1);
    cenario->adicionarObjeto(&MesaPe2);
    cenario->adicionarObjeto(&MesaPe3);
    cenario->adicionarObjeto(&MesaPe4);
    cenario->adicionarObjeto(&MesaCima);

    cenario->adicionarObjeto(&CadeiraPe1);
    cenario->adicionarObjeto(&CadeiraPe2);
    cenario->adicionarObjeto(&CadeiraPe3);
    cenario->adicionarObjeto(&CadeiraPe4);
    cenario->adicionarObjeto(&Cadeira);

    cenario->adicionarObjeto(&AbCorpo);
    cenario->adicionarObjeto(&AbCabeca);

    cenario->adicionarObjeto(&PlantaC);
    cenario->adicionarObjeto(&Jarro);
    cenario->adicionarObjeto(&Tronco);

    cenario->adicionarObjeto(&Moldura1);
    cenario->adicionarObjeto(&Moldura2);
    cenario->adicionarObjeto(&Moldura3);
    cenario->adicionarObjeto(&Moldura4);
    cenario->adicionarObjeto(&Quadro);
    cenario->adicionarObjeto(&QChao);
    cenario->adicionarObjeto(&Cacto1);
    cenario->adicionarObjeto(&Cacto2);
    cenario->adicionarObjeto(&Cacto3);
    cenario->adicionarObjeto(&Abaporu);
    cenario->adicionarObjeto(&Sol);
    cenario->adicionarObjeto(&Sl1);

    cenario->addCamera(camPaint);

    cenario->rayCasting();

    test = cenario->frame;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glClearColor(0, 0, 0, 0);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(H, W);
    glutCreateWindow("CENARIO");

    glutPostRedisplay();

    test = new float[H * W * 3];

    Raycaster();

    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);

    glutMainLoop();

    return 1;
}