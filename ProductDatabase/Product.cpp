#include "splashkit.h"

const int TOTAL_PRODUCTS = 100;
int option;

enum update_database
{
    add_product = 1,
    remove_product = 2,
    update_product = 3,
    sell_product = 4,
    print_status = 5,
    quit_program = 6,
};

struct product
{
    string item_name;
    double cost_price;
    double sale_price;
    int product_count;
};

struct store
{
    product products[TOTAL_PRODUCTS];
    int product_counter = 0;
    double sales_details;
    double profit_details;
};

void populate_array(product &data)
{
    string item_name = read_line();
    double cost_price = std::stod(read_line());
    double sale_price = std::stod(read_line());
    int product_count = std::stoi(read_line());
};

void populate_array(store &data)
{
    data.sales_details = std::stod(read_line());
    data.profit_details = std::stod(read_line());
};

void print_menu()
{
    printf("\nMenu\n");
    printf("\nCAMPUS_CORNER_CAFE_DATABASE\n");
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. Update a product\n");
    printf("4. Sell a product\n");
    printf("5. Stock status\n");
    printf("6. Quit\n");
}

void addproduct(store &store)
{
    product this_product;
    printf("Enter Product Name: ");
    this_product.item_name = read_line();
    printf("Enter Product Cost: ");
    this_product.cost_price = std::stoi(read_line());
    printf("Enter Product Sales: ");
    this_product.sale_price = std::stoi(read_line());
    printf("Enter Product Count: ");
    this_product.product_count = std::stoi(read_line());
    store.products[store.product_counter] = this_product;
    store.product_counter = store.product_counter + 1;
}

void removeproduct(store &store)
{
    product this_product;
    printf("Select the position of the product you wish to remove: ");
    int index = std::stoi(read_line());
    if (index >= 0 && index < store.product_counter)
    {
        store.products[index] = store.products[store.product_counter - 1];
        store.product_counter--;
    }
    else
    {
        printf("Sorry, that is not a valid index.\n");
    }
}

void updateproduct(store &store)
{
    product this_product;
    printf("Update your desired product details: ");
    int index = std::stoi(read_line());
    if (index >= 0 && index < store.product_counter)
    {
        printf("Enter Product Name: ");
        this_product.item_name = read_line();
        printf("Enter Product Cost: ");
        this_product.cost_price = std::stoi(read_line());
        printf("Enter Product Sales: ");
        this_product.sale_price = std::stoi(read_line());
        printf("Enter Product Count: ");
        this_product.product_count = std::stoi(read_line());
        store.products[store.product_counter] = this_product;
        double sale_price = store.products[index].sale_price;
        double cost_price = store.products[index].cost_price;
    }
    else
    {
        printf("Sorry, that is not a valid index.\n");
    }
}

void sellproduct(store &store)
{
    product this_product;
    printf("Select the position of the product you wish to sell: ");
    int index = std::stoi(read_line());
    if (index >= 0 && index < store.product_counter)
    {
        double sale_price = store.products[index].sale_price;
        double cost_price = store.products[index].cost_price;
        store.products[index] = store.products[store.product_counter - 1];
        store.product_counter--;
        store.sales_details += sale_price;
        store.profit_details += sale_price - cost_price;
    }
    else
    {
        printf("Sorry, that is not a valid index.\n");
    }
}

void stockstatus(store &store)
{
    printf("This is all information about our store:\n");
    for (int i = 0; i < store.product_counter; i++)
    {
        printf("Product %d: %s, Cost: %.2f, Sale: %.2f, Count: %d\n", i + 1, store.products[i].item_name.c_str(), store.products[i].cost_price, store.products[i].sale_price, store.products[i].product_count);
    }
    printf("Total Sales: %.2f\n", store.sales_details);
    printf("Total Profit: %.2f\n", store.profit_details);
}

int main()
{
    store my_store;
    my_store.product_counter = 0;
    my_store.sales_details = 0;
    my_store.profit_details = 0;

    do
    {
        print_menu();

        printf("Choose an option: ");
        option = std::stoi(read_line());

        switch (option)
        {
        case 1:
            addproduct(my_store);
            break;

        case 2:
            removeproduct(my_store);
            break;

        case 3:
            updateproduct(my_store);
            break;

        case 4:
            sellproduct(my_store);
            break;

        case 5:
            stockstatus(my_store);
            break;

        case 6:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid option. Try again.\n");
        }

    } while (option != quit_program);

    return 0;
}
