/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:33:12 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/09 23:48:48 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_push_swap **create_sorted_array(t_push_swap *stack, int size)
{
    t_push_swap **sorted_array;
    t_push_swap *current;
    int i = 0;
    
    sorted_array = (t_push_swap **)malloc(sizeof(t_push_swap *) * size);
    current = stack;
    i = 0;
    while (i < size)
    {
        sorted_array[i] = current;
        current = current->next;
        i++;
    }
    return sorted_array;
}

void bubble_sort_array(t_push_swap **arr, int size)
{
    int i;
    int j;
    t_push_swap *temp;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (arr[j]->value > arr[j + 1]->value)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

void set_indices_from_array(t_push_swap **arr, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        arr[i]->index = i;
        i++;
    }
}

void assign_indices(t_push_swap **stack)
{
    int size;
    t_push_swap **sorted_array;

    size = push_swap_lstsize(*stack);
    sorted_array = create_sorted_array(*stack, size);
    bubble_sort_array(sorted_array, size);
    set_indices_from_array(sorted_array, size);

    free(sorted_array);
}