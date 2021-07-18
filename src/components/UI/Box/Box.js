import React from 'react';
import { Card } from 'react-bootstrap';
import styled from 'styled-components';

const StyledCard = styled(Card)`
    margin-top: ${props => props.className === "profile" ? '10rem' : 0 };
    background: #000000;
    border: 1px solid #40E83C;
    & .data {
        font-size:30px;
        color: #40E83C;
        border: none;
        & p {
            margin: 10px;
            & span {
                font-weight: bold;
            } 
        }
    }
    @media (min-width: 481px) and (max-width: 767px) {
        & .data {
            font-size: 20px;
        }
    }
    @media (max-width: 480px) {
        & .data {
            font-size: 15px;
        }
    }
`;
 
const Box = (props) => {
    const classes = props.className ? props.className : '';
    return(
        <StyledCard className = {classes}>{props.children}</StyledCard>
    );
}

export default Box;