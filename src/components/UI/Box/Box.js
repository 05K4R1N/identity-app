import React from 'react';
import { Card } from 'react-bootstrap';
import styled from 'styled-components';

const StyledCard = styled(Card)`
    margin-top: ${props => props.className == "profile" ? '6rem' : 0 };
`;
 
const Box = (props) => {
    const classes = 'card ' + props.className;
    return(
        <StyledCard className = {props.className}>{props.children}</StyledCard>
    );
}

export default Box;