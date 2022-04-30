/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayscasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:39:38 by lauremass         #+#    #+#             */
/*   Updated: 2022/04/30 12:04:58 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	castAllRays(t_player *player)
{
	float	rayAngle;
	int		stripId;

	rayAngle = player->rotationAngle - (FOV_ANGLE / 2);
	stripId = 0;
	while (stripId < NUM_RAYS)
	{
		castVerticalRay    (rayAngle, stripId);
		rayAngle += FOV_ANGLE / NUM_RAYS;
		stripId++;
	}

}

void	castRay(float rayAngle, int stripId)
{
	 int	isRayFacingDown; //Vertical
	 int	isRayFacingUp;// Vertical
	 int	isRayFacingRight; //Horizontal
	 int	isRayFacingLeft; //Horizontal

	 isRayFacingDown = 0;
	 isRayFacingRight = 0;
	if (0 < rayAngle && rayAngle < M_PI)
		isRayFacingDown = 1;
	if (rayAngle < (0.5 * M_PI) || rayAngle > (1.5 * M_PI))
		isRayFacingRight = 1;
	isRayFacingUp = !isRayFacingDown;
	isRayFacingLeft = !isRayFacingRight;



}
