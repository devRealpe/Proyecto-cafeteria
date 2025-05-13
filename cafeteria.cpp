#include <iostream>
using namespace std;

struct Comida
{
    string nombre;
    double precio;
    int cantidad;
};

int main()
{
    Comida inventario[100];
    inventario[0].nombre = "Cafe";
    inventario[0].precio = 1.50;
    inventario[0].cantidad = 10;
    inventario[1].nombre = "Torta";
    inventario[1].precio = 2.00;
    inventario[1].cantidad = 5;
    inventario[2].nombre = "Galleta";
    inventario[2].precio = 0.50;
    inventario[2].cantidad = 20;
    inventario[3].nombre = "Soda";
    inventario[3].precio = 1.00;
    inventario[3].cantidad = 15;
    inventario[4].nombre = "Agua";
    inventario[4].precio = 0.75;
    inventario[4].cantidad = 25;
    inventario[5].nombre = "Ensalada";
    inventario[5].precio = 3.00;
    inventario[5].cantidad = 8;
    inventario[6].nombre = "Sandwich";
    inventario[6].precio = 2.50;
    inventario[6].cantidad = 12;
    inventario[7].nombre = "Pizza";
    inventario[7].precio = 3.50;
    inventario[7].cantidad = 6;
    inventario[8].nombre = "Pasta";
    inventario[8].precio = 4.00;
    inventario[8].cantidad = 4;
    inventario[9].nombre = "Fruta";
    inventario[9].precio = 1.25;
    inventario[9].cantidad = 30;
    inventario[10].nombre = "Postre";
    inventario[10].precio = 2.50;
    inventario[10].cantidad = 10;

    int cantidadProductos = 5;
    string contrasena = "admin123";
    int rol;
    cout << "Seleccione el rol: " << endl;
    cout << "1. Administrador" << endl;
    cout << "2. Usuario" << endl;
    cin >> rol;

    if (rol == 1)
    {
        string contrasenaIngresada;
        bool accesoConcedido = false;

        for (int i = 3; i > 0; i--)
        {
            cout << "Ingrese la contrasena: ";
            cin >> contrasenaIngresada;

            if (contrasenaIngresada == contrasena)
            {
                accesoConcedido = true;
                break;
            }
            else
            {
                cout << "La contraseña es incorrecta" << endl;
                if (i - 1 > 0)
                    cout << "Le quedan " << i - 1 << " intento(s)" << endl;
                else
                    cout << "Ha superado el número máximo de intentos " << endl;
            }
        }
        if (accesoConcedido)
        {
            while (true)
            {
                cout << "Bienvenido Administrador" << endl;
                int opcionAdministrador;
                cout << "Seleccione una opción" << endl;
                cout << "1. Ver reporte de ventas" << endl;
                cout << "2. Gestionar productos" << endl;
                cin >> opcionAdministrador;

                if (opcionAdministrador == 1)
                {
                    cout << "Reporte de ventas" << endl;
                }
                else if (opcionAdministrador == 2)
                {
                    int opcionGestionproducto;
                    cout << "Gestionar productos" << endl;
                    cout << "Seleccione una opción" << endl;
                    cout << "1. Agregar Producto" << endl;
                    cout << "2. Eliminar Producto" << endl;
                    cout << "3. Editar Producto" << endl;
                    cout << "4. Mostrar Inventario" << endl;
                    cout << "5. Salir" << endl;
                    cin >> opcionGestionproducto;

                    if (opcionGestionproducto == 1)
                    {
                        cout << "Agregar Producto" << endl;
                        string nombreProducto;
                        double precioProducto;
                        int cantidadProducto;
                        cout << "Ingrese el nombre del producto: ";
                        cin >> nombreProducto;
                        cout << "Ingrese el precio del producto: ";
                        cin >> precioProducto;
                        cout << "Ingrese la cantidad del producto: ";
                        cin >> cantidadProducto;

                        inventario[cantidadProductos].nombre = nombreProducto;
                        inventario[cantidadProductos].precio = precioProducto;
                        inventario[cantidadProductos].cantidad = cantidadProducto;

                        cantidadProductos++;
                        cout << "Producto agregado exitosamente!" << endl;
                    }
                    else if (opcionGestionproducto == 2)
                    {
                        cout << "Eliminar Producto" << endl;
                        string nombreProductoEliminar;
                        cout << "Ingrese el nombre del producto a eliminar: ";
                        cin >> nombreProductoEliminar;
                        bool encontrado = false;
                        for (int i = 0; i < cantidadProductos; i++)
                        {
                            if (inventario[i].nombre == nombreProductoEliminar)
                            {
                                encontrado = true;
                                for (int j = i; j < cantidadProductos - 1; j++)
                                {
                                    inventario[j] = inventario[j + 1];
                                }
                                cantidadProductos--;
                                cout << "Producto eliminado exitosamente!" << endl;
                                break;
                            }
                        }
                        if (encontrado == false)
                        {
                            cout << "Producto no encontrado" << endl;
                        }
                    }
                    else if (opcionGestionproducto == 3)
                    {
                        cout << "Editar Producto" << endl;
                        string nombreProductoEditar;
                        cout << "Ingrese el nombre del producto a editar: ";
                        cin >> nombreProductoEditar;
                        bool encontrado = false;
                        for (int i = 0; i < cantidadProductos; i++)
                        {
                            if (inventario[i].nombre == nombreProductoEditar)
                            {
                                encontrado = true;
                                cout << "Ingrese el nuevo nombre del producto: ";
                                cin >> inventario[i].nombre;
                                cout << "Ingrese el nuevo precio del producto: ";
                                cin >> inventario[i].precio;
                                cout << "Ingrese la nueva cantidad del producto: ";
                                cin >> inventario[i].cantidad;
                                cout << "Producto editado exitosamente!" << endl;
                                break;
                            }
                        }
                    }
                    else if (opcionGestionproducto == 4)
                    {
                        cout << "Mostrar Inventario" << endl;
                        for (int i = 0; i < cantidadProductos; i++)
                        {
                            cout << "Nombre: " << inventario[i].nombre << endl;
                            cout << "Precio: " << inventario[i].precio << endl;
                            cout << "Cantidad: " << inventario[i].cantidad << endl;
                            cout << "------------------------" << endl;
                        }
                    }
                    else if (opcionGestionproducto == 5)
                    {
                        cout << "Salir" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Opcion no valida" << endl;
                    }
                }
                else
                {
                    cout << "Opcion no valida" << endl;
                }
            }
        }
    }
    else if (rol == 2)
    {
        cout << "Bienvenido Usuario" << endl;
        // Aqui puedes agregar el menu de usuario+
        while (true)
        {
            cout << "Seleccione una opción" << endl;
            cout << "1. Ver menú" << endl;
            cout << "2. Realizar pedido" << endl;
            cout << "3. Salir" << endl;
            int opcionUsuario;
            cin >> opcionUsuario;
            if (opcionUsuario == 1)
            {
                cout << "Menu" << endl;
                for (int i = 0; i < cantidadProductos; i++)
                {
                    cout << "Nombre: " << inventario[i].nombre << endl;
                    cout << "Precio: " << inventario[i].precio << endl;
                    cout << "Cantidad: " << inventario[i].cantidad << endl;
                    cout << "------------------------" << endl;
                }
            }
            else if (opcionUsuario == 2)
            {
                cout << "Realizar pedido" << endl;
                // Aqui puedes agregar la logica para realizar un pedido
                string nombreProductoPedido;
                cout << "Ingrese el nombre del producto a pedir: ";
                cin >> nombreProductoPedido;
                bool encontrado = false;
                for (int i = 0; i < cantidadProductos; i++)
                {
                    if (inventario[i].nombre == nombreProductoPedido)
                    {
                        encontrado = true;
                        if (inventario[i].cantidad > 0)
                        {
                            inventario[i].cantidad--;
                            cout << "Pedido realizado exitosamente!" << endl;
                        }
                        else
                        {
                            cout << "Producto no disponible" << endl;
                        }
                        break;
                    }
                }
            }
            else if (opcionUsuario == 3)
            {
                cout << "Salir" << endl;
                break;
            }
            else
            {
                cout << "Opcion no valida" << endl;
            }
        }
    }
    else
    {
        cout << "Rol no valido" << endl;
    }
}